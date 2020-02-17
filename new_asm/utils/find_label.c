/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_label.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 16:58:48 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/17 16:20:43 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char	*clean_label(char *label)
{
	char	*new;
	int		i;
	int		j;

	new = ft_strnew(ft_strlen(label));
	i = 0;
	j = 0;
	while (label[i])
	{
		if (ft_strchr(LABEL_CHARS, label[i]))
		{
			new[j] = label[i];
			j++;
		}
		i++;
	}
	return (new);
}

/*
**	@desc	- Finds the line which the label with passed name represents.
**	@param	- t_label *label, linked list of all the labels saved.
**			- char *name, str by which the label is found.
**			- int line, for error message.
**	@return	- int, the line which is represented by the label.
*/

int			find_label(t_label *label, char *name, int line)
{
	char *clean;

	clean = clean_label(name);
	while (label && ft_strcmp(clean, label->name))
		label = label->next;
	free(clean);
	if (!label)
		error("Label not found", line);
	return (label->line);
}
