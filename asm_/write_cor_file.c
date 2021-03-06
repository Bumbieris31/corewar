/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_cor_file.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 19:01:19 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/25 16:57:45 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@descr	- For writing the magic header at the beginning of the file to be\
**			- recognized as a valid .cor.
*/

void		write_magic_header(int wfd)
{
	int	magic;

	magic = swap_4_bytes(COREWAR_EXEC_MAGIC);
	write(wfd, &magic, 4);
}

/*
**	@descr	- For writing strings in the format necesary for .cor files.
*/

void		write_str(char *name, int limit, int wfd)
{
	int		i;
	char	c;

	i = 0;
	while (name[i])
	{
		c = name[i];
		write(wfd, &c, 1);
		i++;
	}
	i = limit - i;
	if (i > 0)
		write_null_bytes(i, wfd);
}

/*
**	@descr	- Main writing function that executes functions for all the .cor\
**			- file parts.
*/

void		write_cor_file(t_asm *data)
{
	write_magic_header(data->wfd);
	write_str(data->name, PROG_NAME_LENGTH, data->wfd);
	write_null_bytes(4, data->wfd);
	write_size(data->parts, data->wfd);
	write_str(data->comment, COMMENT_LENGTH, data->wfd);
	write_null_bytes(4, data->wfd);
	write_champ_byte(data);
}
