/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_label.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:29:14 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/17 18:25:44 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- function adds label if a label is followed by a label
**	@param	- char *s, the label name
**			- t_label *head, to already existing label
*/

static void	add_to_label(t_asm *data, char *s, t_label **head)
{
	t_label	*curr;
	t_label	*new;

	curr = (*head);
	new = make_label(data, s, -1);
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

/*
**	@desc	- function sets the line of the labels
**	@param	- t_label *head, head of the labels found
**			- int line, line number to set to
*/

static void	set_lines(t_label *head, int line)
{
	t_label	*curr;

	curr = head;
	while (curr)
	{
		curr->line = line;
		curr = curr->next;
	}
}

/*
**	@desc	- function get the label variables if its not on the same line
**	@param	- t_asm *data, main struct
**			- char *name, name of the label
*/

void		get_next_label(t_asm *data, char *name)
{
	int		last;
	int		line_nb;
	char	*s;
	char	**split;
	t_label	*new;

	split = NULL;
	new = make_label(data, name, -1);
	last = 1;
	line_nb = data->lines;
	while (get_line(data, data->rfd, &s, NULL))
	{
		if (s && !ft_strequ("", s))
		{
			last = 0;
			split = ft_strsplit_ws(s);
//
//			if next line is oper
			if (check_instruction(split[0]))
			{
				set_lines(new, data->lines);
				add_label(data, &new);
				parse_instruction(data, split);
				break ;
			}
//
//			if next line is a label
			else if (split[0][ft_strlen(s) - 1] == LABEL_CHAR)
				add_to_label(data, split[0], &new);
//
//			if no ws after label and more op
			else if (ft_strchr(split[0], LABEL_CHAR))
			{
				add_label(data, &new);
				set_lines(new, data->lines);
				get_label(data, split);
				break ;
			}
			else
				error("Invalid label", data->lines);
		}
		free_arr(&s, &split, 2);
	}
	free_arr(&s, &split, 2);
	if (last)
	{
		set_lines(new, line_nb);
		add_label(data, &new);
	}
}

/*
**	@desc	- function checks if label syntax is valid
**	@param	- char *label, label to check
**			- int line, nb of the line label is in
*/

static void	label_syntax(char *label, int line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (label[i])
	{
		if (label[i] == LABEL_CHAR)
			count++;
		i++;
	}
	if (count > 1)
		error("Invalid label syntax", line);
}

/*
**	@desc	- function gets the label and all the variables
**	@param	- t_asm *data, main struct
**			- char **line, line read, split on whitespace
*/

void		get_label(t_asm *data, char **line)
{
	t_label		*new;
	char		**split;
	int			line_nb;

	split = NULL;
	label_syntax(line[0], data->lines);
	split = ft_strsplit(line[0], LABEL_CHAR);
	if (split[1])
	{
		new = make_label(data, split[0], data->lines);
		add_label(data, &new);
		ft_strclr(line[0]);
		line[0] = ft_strdup(split[1]);
		parse_instruction(data, line);
	}
	else if (line[1] && check_instruction(line[1]))
	{
		line_nb = data->lines;
		parse_instruction(data, &line[1]);
		new = make_label(data, split[0], line_nb);
		add_label(data, &new);
	}
	else
		get_next_label(data, split[0]);
	free_arr(NULL, &split, 1);
}
