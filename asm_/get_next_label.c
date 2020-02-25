/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_label.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 19:41:35 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/25 21:01:12 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static int	add_instr_line(t_label *new, t_asm *data, char ***split)
{
	set_lines(new, data->lines);
	add_label(data, &new);
	parse_instruction(data, *split);
	free_arr(NULL, split, 1);
	return (1);
}

int			add_parts_to_data(char *str, t_asm *data, t_label *new)
{
	char	**split;

	split = NULL;
	split = ft_strsplit_ws(str);
	if (check_instruction(split[0]))
		return (add_instr_line(new, data, &split));
	else if (split[0][ft_strlen(str) - 1] == LABEL_CHAR)
		add_to_label(data, split[0], &new);
	else if (ft_strchr(split[0], LABEL_CHAR))
	{
		add_label(data, &new);
		set_lines(new, data->lines);
		get_label(data, split);
		free_arr(NULL, &split, 1);
		return (1);
	}
	else
	{
		free_arr(&str, &split, 2);
		error("Invalid label", data->lines);									// free data
	}
	return (0);
}

/*
**	@desc	- function get the label variables if its not on the same line
**	@param	- t_asm *data, main struct
**			- char *name, name of the label
*/

void		get_next_label(t_asm *data, char *name)
{
	int		last;
	char	*str;
	t_label	*new;

	new = make_label(data, name, -1);
	last = 1;
	while (get_line(data, data->rfd, &str, NULL))
	{
		if (str && !ft_strequ("", str))
		{
			last = 0;
			if (add_parts_to_data(str, data, new))
			{
				ft_strdel(&str);
				break ;
			}
		}
	}
	ft_strdel(&str);
	if (last)
	{
		set_lines(new, data->lines);
		add_label(data, &new);
	}
}

/*
void		get_next_label(t_asm *data, char *name)
{
	char	*str;
	int		last;
	char	**split;
	t_label	*new;

	split = NULL;
	new = make_label(data, name, -1);
	last = 1;
	while (get_line(data, data->rfd, &str, NULL))
	{
		if (str && !ft_strequ("", str))
		{
			last = 0;
			split = ft_strsplit_ws(str);
			if (check_instruction(split[0]))
			{
				set_lines(new, data->lines);
				add_label(data, &new);
				parse_instruction(data, split);
				break ;
			}
			else if (split[0][ft_strlen(str) - 1] == LABEL_CHAR)
				add_to_label(data, split[0], &new);
			else if (ft_strchr(split[0], LABEL_CHAR))
			{
				add_label(data, &new);
				set_lines(new, data->lines);
				get_label(data, split);
				break ;
			}
			else
				error("Invalid label", data->lines);									// free data
		}
		free_arr(&str, &split, 2);
	}
	free_arr(&str, &split, 2);
	if (last)
	{
		set_lines(new, data->lines);
		add_label(data, &new);
	}
}
 */