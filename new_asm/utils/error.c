/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 14:54:36 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/06 17:15:38 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- function prints the usage of the program
*/

static void	usage(void)
{
	int		fd;
	char	*line;

	fd = open("./utils/usage_msg.txt", O_RDONLY);
	line = NULL;
	while (0 < get_next_line(fd, &line))
	{
		ft_printf("%s\n", line);
		if (line)
			ft_strdel(&line);
	}
	close(fd);
	exit(0);
}

/*
**	@desc 	- prints error message and exits
**	@param	- string message to be printed
*/

void		error(char *message, int line)
{
	if (ft_strequ(message, "usage"))
		usage();
	if (line)
		ft_printf("Error in line %d: ");
	else
		ft_printf("Error: ");
	ft_putendl(message);
	exit(1);
}
