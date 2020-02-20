/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_cor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 17:52:45 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/20 15:56:17 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@descr	- Writes null bytes to the file descriptor specified by wfd.
*/

void		write_null_bytes(int n, int wfd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(wfd, "\0", 1);
		i++;
	}
}

/*
**	@descr	- Creates a valid .cor file to be filled with champ information.
*/

void		create_cor(t_asm *data)
{
	char	*name;

	data->char_name[ft_strlen(data->char_name) - 1] = '\0';
	name = ft_strjoin(data->char_name, "cor");
	data->wfd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	write_cor_file(data);
	ft_strdel(&name);
}
