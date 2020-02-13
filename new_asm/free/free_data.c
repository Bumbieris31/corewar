/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 16:57:27 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/13 16:57:52 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/asm.h>

void	free_labels(t_label *label)
{
	t_label	*curr;

	while (label)
	{
		curr = label->next;
		if (label->name)
			free(label->name);
		if (label)
			free(label);
		label = curr;
	}
}

void	free_parts(t_parts *parts)
{
	t_parts	*curr;

	while (parts)
	{
		curr = parts->next;
		if (parts->name)
			free(parts->name);
		if (parts)
			free(parts);
		parts = curr;
	}
}

/*
**	@desc	- function frees main struct
**	@param	- t_asm *data, main struct
*/

void	free_data(t_asm *data)
{
	if (data && data->comment)
		free(data->comment);
	if (data && data->name)
		free(data->name);
	free_labels(data->labels);
	free_parts(data->parts);
	if (data)
		free(data);
}
