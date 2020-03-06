/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_label.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 14:48:34 by asulliva       #+#    #+#                */
/*   Updated: 2020/03/06 14:50:41 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

char		*clean_label(char *label)
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
