/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   champ_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 13:23:20 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 15:08:27 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**  @desc   - function checks for nullbytes in file
**  @param  - const int fd, file descriptor
**  @return - 0 on error, !0 on succes
*/

int			null_byte(const int fd)
{
	uint32_t	null_byte;
	uint8_t		*null_byte_ref;

	if ((read(fd, &null_byte, 4) <= 4))
	{
		null_byte_ref = (uint8_t *)&null_byte;
		return (
		null_byte_ref[0] == 0 &&
		null_byte_ref[1] == 0 &&
		null_byte_ref[2] == 0 &&
		null_byte_ref[3] == 0);
	}
	return (0);
}

/*
**	@desc	- function checks if the code size is correct
**	@param	- t_champ *champ, pointer to champion
**			- const int fd, file descriptor for champ
**	@return	- 1 on success, 0 on error
*/

int			champ_code_size(t_champ *champ, const int fd)
{
	uint32_t num;

	if (read(fd, &num, 4) < 4)
		return (0);
	num = swap_32(num);
	if (CHAMP_MAX_SIZE < num)
		return (0);
	champ->size = (int)num;
	return (1);
}

/*
**	@desc	- function checks if T_REG args are in bounds
**	@param	- int *code, exec code
**			- int opcode, opcode to check
**			- int pc, program counter (jump to next op)
**	@return	- 1 on success, 0 on error
*/

static int	check_regs(t_byte *code, t_byte opcode, int pc)
{
	e_argctype	args[3];
	int			i;

	i = 0;
	decode(code[pc + 1], args);
	pc += 2;
	while (i < 3)
	{
		if (args[i] == T_REG && REG_NUMBER < code[pc])
			return (0);
		pc += arg_size(args[i], opcode);
		i++;
	}
	return (1);
}

/*
**	@desc	- functions checks the exec code for errors
**	@param	- int *code, exec code
**			- int size, size of the code
**	@return	- 1 on success, 0 on error
*/

static int	check_code(t_byte *code, int size)
{
	int		pc;
	t_byte	opcode;

	pc = 0;
	while (pc < size)
	{
		opcode = code[pc];
		if (g_op_tab[opcode].octal == 1)
		{
			if (!check_regs(code, opcode, pc))
				return (0);
		}
		pc += get_pc(opcode, code[pc + 1]);
	}
	return (1);
}

/*
**	@desc	- function gets exec code out of file
**	@param	- t_champ *champ, pointer to champion
**			- const int fd, file descriptor for champ file
**	@return	- 1 on success, 0 on error
*/

int			get_champ_code(t_champ *champ, const int fd)
{
	int		ret;

	champ->code = (t_byte *)ft_memalloc(champ->size);
	ft_bzero(champ->code, champ->size);
	ret = read(fd, champ->code, champ->size);
	if (ret != champ->size)
		return (0);
	if (!check_code(champ->code, champ->size))
		return (0);
	return (1);
}