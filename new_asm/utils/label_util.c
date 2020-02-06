/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label_util.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:44:17 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/06 17:04:44 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- function checks if the label contains only the allowed characters
**	@param	- char *label, name of the label to be checked
**	@return	- int, 0 if not valid
**			- 1 if valid
*/

static int	check_label(char *label)
{
	int		i;

	i = 0;
	while (label[i] != '\0')
	{
		if (!ft_strchr(LABEL_CHARS, label[i]))
			return (0);
		i++;
	}
	return (1);
}

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
**	@desc	- adds a label to the linked list of labels
**	@param	- t_asm *data, main struct
**			- t_label *new, label to be added
*/

void		add_label(t_asm *data, t_label **new)
{
	t_label	*curr;

	curr = data->labels;
	if (!curr)
	{
		data->labels = (*new);
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = (*new);
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
	new->name = ft_strdup(name);
	new->line = line;
	new->next = NULL;
	return (new);
}
