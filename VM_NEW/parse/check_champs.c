/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   champs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 20:30:58 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 12:06:35 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- checks file is valid
**	@param	- char *name, name of the file
**	@return	- 1 on success, 0 on failure
*/

static int	check_file(char *name)
{
	int		fd;
	char	c;

	fd = open(name, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("%{RED_B}Can't open file [%s]\n", name);
		ft_printf("%{RESET}");
		return (0);
	}
	else if (read(fd, &c, 0) < 0)
	{
		ft_printf("%{RED_B}Can't read from file [%s]\n", name);
		ft_printf("%{RESET}");
		return (0);
	}
	close(fd);
	return (1);
}

/*
**	@desc	- checks if file name is correct
**	@param	- char *name, file name
**	@return	- 1 on succes, 0 on failure
*/

int			check_champion(char *name)
{
	int		len;

	len = ft_strlen(name);
	if (5 <= len && ft_strstr(&name[len - 4], ".cor"))
		return (1);
	return (0);
}

/*
**	@desc	- function saves new players and returns filenames
**	@param	- char *name, name of the file
**	@return	- char **player_files, the names of the files
*/

char		**save_players(char *name)
{
	static char	**player_files;
	static int	i;

	if (i == 0)
		player_files = (char**)ft_memalloc(sizeof(char*) * MAX_PLAYERS);
	if (name && !ft_strcmp((const char*)name, "free it"))
	{
		while (0 < i)
		{
			i--;
			ft_strdel(&player_files[i]);
		}
		free(player_files);
	}
	else if (name)
	{
		player_files[i] = (char *)ft_memalloc(ft_strlen(name));
		player_files[i] = (char *)ft_strcpy(player_files[i], name);
		i++;
	}
	return (player_files);
}

/*
**	@desc	- main champion parsing function
**	@param	- char *name, champ file
**	@return	- 1 on succes, 0 on failure
*/

int			champ_name(char *name)
{
	if (check_champion(name))
	{
		if (check_file(name))
		{
			save_players(name);
			return (1);
		}
	}
	return (0);
}