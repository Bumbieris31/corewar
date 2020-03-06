/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label_util.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 15:12:06 by asulliva       #+#    #+#                */
/*   Updated: 2020/03/06 14:51:46 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@desc	- removes label_char from string
**	@param	- char *s, string to be modified
**	@return	- char *new, new string without label_char
*/

static char	*rm_label_char(char *s, int line)
{
	char	*new;
	int		i;
	int		count;

	new = ft_strdup(s);
	i = 0;
	count = 0;
	while (new[i])
	{
		if (new[i] == LABEL_CHAR)
		{
			count++;
			new[i] = '\0';
		}
		i++;
	}
	if (count > 1)
		error("Invalid syntax", line);
	return (new);
}

/*
**	@desc	- function adds label if a label is followed by a label
**	@param	- char *s, the label name
**			- t_label *head, to already existing label
*/

void		add_to_label(t_asm *data, char *s, t_label **head)
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

void		set_lines(t_label *head, int line)
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
**	@desc	- fuction makes a new label object
**	@param	- char *s, name of the label
**			- int line, line number the label points to
*/

t_label		*make_label(t_asm *data, char *s, int line)
{
	t_label	*new;
	char	*name;

	name = rm_label_char(s, data->lines);
	if (!check_label(name))
		error("Invalid label name", data->lines);
	new = (t_label*)malloc(sizeof(t_label));
	new->name = name;
	new->line = line;
	new->next = NULL;
	return (new);
}
