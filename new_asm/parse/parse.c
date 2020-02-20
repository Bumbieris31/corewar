/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 15:51:26 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/20 18:37:45 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- function picks which parsing function to call
**	@param	- t_asm *data, main struct
**			- char *s, line read from the file
*/

void		choose_parse(t_asm *data, char *s)
{
	if (s && ft_strlen(s) > 0)
	{
//		if (ft_strequ(s, "hophop:"))
//			print_parts(data->parts);
		if (!ft_strncmp(s, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			parse_nc(data, s, 0);
		else if (!ft_strncmp(s, COMMENT_CMD_STRING,\
		ft_strlen(COMMENT_CMD_STRING)))
			parse_nc(data, s, 1);
		else
			parse_label(data, s);
	}
}

/*
**	@desc	- main parsing function
**	@param	- t_asm *data, main struct
*/

void		parse(t_asm *data)
{
	char	*s;

	while (get_line(data, data->rfd, &s, NULL))
	{
		if (s && ft_strlen(s) > 0)
			choose_parse(data, s);
		free(s);
	}
	free(s);
}
