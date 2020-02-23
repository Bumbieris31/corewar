/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 18:25:09 by asulliva       #+#    #+#                */
<<<<<<< HEAD:dsm_/write.c
/*   Updated: 2020/01/30 15:12:56 by krioliin      ########   odam.nl         */
=======
/*   Updated: 2020/02/23 14:38:44 by asulliva      ########   odam.nl         */
>>>>>>> aidan:dsm_/write.c
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc	- functions writes the name and comment into the file
**	@param	- t_dsm *data, main struct
*/

static void	write_header(t_dsm *data)
{
	ft_putstr_fd(".name\t\t", data->wfd);
	ft_putchar_fd('\"', data->wfd);
	ft_putstr_fd(data->name, data->wfd);
	ft_putstr_fd("\"\n", data->wfd);
	ft_putstr_fd(".comment\t", data->wfd);
	ft_putchar_fd('\"', data->wfd);
	ft_putstr_fd(data->comment, data->wfd);
	ft_putstr_fd("\"\n\n", data->wfd);
}

/*
**	@desc	- functions writes the code into the file
**	@param	- t_dsm *data, main struct
*/

static void	write_code(t_dsm *data)
{
<<<<<<< HEAD:dsm_/write.c
	t_oop	*curr;
=======
	t_oper	*curr;
>>>>>>> aidan:dsm_/write.c
	int		i;

	curr = data->ops;
	while (curr)
	{
		ft_putchar_fd('\t', data->wfd);
		ft_putstr_fd(curr->op_name, data->wfd);
		i = 0;
		while (curr->args[i + 1])
		{
			ft_putstr_fd(curr->args[i], data->wfd);
			ft_putchar_fd(' ', data->wfd);
			i++;
		}
		ft_putstr_fd(curr->args[i], data->wfd);
		ft_putchar_fd('\n', data->wfd);
		curr = curr->next;
	}
}

/*
**	@desc	- main controller writing function
**	@param	- t_dsm *data, main struct
*/

void		write_file(t_dsm *data)
{
	char	*name;

	data->file_name[ft_strlen(data->file_name) - 3] = '\0';
	name = ft_strjoin(data->file_name, "s");
	data->wfd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	free_arr(&name, NULL, 0);
	write_header(data);
	write_code(data);
	close(data->wfd);
}
