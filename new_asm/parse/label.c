/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:16:05 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/06 17:21:15 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- parses the labels and the instructions
**	@param	- t_asm *data, main struct
**			- char *s, line read
*/

void		parse_label(t_asm *data, char *s)
{
	char	**split;

	data->wfd = 0;
	split = NULL;
	split = ft_strsplit_ws(s);
	if (check_instruction(split[0]))
		parse_instruction(data, split);
	else
	{
		if (!ft_strchr(split[0], LABEL_CHAR))
			error("Not a valid instruction", data->lines);
		else
			get_label(data, split);
	}
	free_arr(NULL, &split, 1);
}
