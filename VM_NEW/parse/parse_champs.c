/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_champs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 12:03:41 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 15:57:22 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function gets champ name out of file
**	@param	- t_champ *champ, pointer to champ
**			- const int fd, file descriptor
**	@return	- 1 on success, 0 on error
*/

static int		get_champ_name(t_champ *champ, const int fd)
{
	char	champ_name[PROG_NAME_LENGTH + 1];

	ft_bzero(champ_name, PROG_NAME_LENGTH + 1);
	if (read(fd, champ_name, PROG_NAME_LENGTH) >= PROG_NAME_LENGTH)
	{
		champ->name = ft_strdup(champ_name);
		return (1);
	}
	return (0);
}

/*
**	@desc	- function gets champ comment out of file
**	@param	- t_champ *champ, pointer to champ
**			- const int fd, file descriptor
**	@return	- 1 on success, 0 on error
*/

static int		get_champ_comment(t_champ *champ, const int fd)
{
	char	champ_comment[COMMENT_LENGTH + 1];

	ft_bzero(champ_comment, COMMENT_LENGTH + 1);
	if (read(fd, champ_comment, COMMENT_LENGTH) >= COMMENT_LENGTH)
	{
		champ->comment = ft_strdup(champ_comment);
		return (1);
	}
	return (0);
}

/*
**	@desc	- function checks magic header in file
**	@param	- const int fd, file descriptor
**	@return	- 0 on error, !0 on succes
*/

static int		is_magic_header(const int fd)
{
	uint32_t	magic_number_input;
	uint32_t	magic_number_reference;
	uint8_t		*m_in;
	uint8_t		*m_ref;

	if (read(fd, &magic_number_input, 4) < 4)
		return (false);
	magic_number_reference = COREWAR_EXEC_MAGIC;
	m_in = (uint8_t *)&magic_number_input;
	m_ref = (uint8_t *)&magic_number_reference;
	return ((
		m_ref[0] == m_in[0] &&
		m_ref[1] == m_in[1] &&
		m_ref[2] == m_in[2] &&
		m_ref[3] == m_in[3])
		|| (
		m_ref[0] == m_in[3] &&
		m_ref[1] == m_in[2] &&
		m_ref[2] == m_in[1] &&
		m_ref[3] == m_in[0]));
}

/*
**	@desc	- function for initializing single champ
**	@param	- char *file, name of the champ file
**			- int fd, file descriptor, should be 0 allways
**	@return	- t_champ new, champ object
*/

static t_champ	init_champ(char *file, int fd)
{
	t_champ	new;

	fd = open((const char*)file, O_RDONLY);
	if (fd < 3)
		error("Parsing champion", file);
	if (!is_magic_header(fd))
		error("Parsing champion", file);
	if (!get_champ_name(&new, fd))
		error("Parsing champion", file);
	if (!null_byte(fd))
		error("Parsing champion", file);
	if (!champ_code_size(&new, fd))
		error("Parsing champion", file);
	if (!get_champ_comment(&new, fd))
		error("Parsing champion", file);
	if (!null_byte(fd))
		error("Parsing champion", file);
	if (!get_champ_code(&new, fd))
		error("Parsing champion", file);
	new.last_live = 0;
	new.lives = 0;
	close(fd);
	return (new);
}

void			print_champ(t_champ champ)
{
	ft_printf(".name [%s]\n.comment [%s]\n", champ.name, champ.comment);
	ft_printf("code size [%d]\n", champ.size);
	ft_printf("starting pos [%d]\n", champ.start_pos);
	ft_printf("champ id [%d]\n", champ.id);
}

/*
**	@desc	- main function for parsing champions
**	@param	- t_vm *vm, main struct
*/

void			parse_champs(t_vm *vm)
{
	int		i;
	char	**files;

	i = 0;
	NB_PLAYERS = get_amount(0);
	files = save_players(NULL);
	CHAMPS = (t_champ*)ft_memalloc(sizeof(t_champ) * NB_PLAYERS);
	if (!CHAMPS)
		error("Parsing champions", NULL);
	while (i < NB_PLAYERS)
	{
		CHAMPS[i] = init_champ(files[i], 0);
		set_champ(&CHAMPS[i], vm->flag->play_order, i, NB_PLAYERS);
		print_champ(CHAMPS[i]);
		i++;
	}
}
