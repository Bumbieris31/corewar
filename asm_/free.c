/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 18:18:10 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/21 18:03:41 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@desc	- function frees up to 3 2D arrays
**	@param	- char **arr1, array to be freed
**			- char **arr2, array to be freed
**			- int flag, 0 if arr1 freed, 1 if arr2 freed, 2 for both
*/

void	free_arr(char **arr1, char ***arr2, int flag)
{
	int		i;

	if ((!flag || flag == 2) && *arr1)
	{
		ft_strdel(arr1);
		*arr1 = NULL;
	}
	if (flag && arr2 && *arr2)
	{
		i = 0;
		while (arr2[0][i])
		{
			if (arr2[0][i])
				free(arr2[0][i]);
			arr2[0][i] = 0;
			i++;
		}
		ft_strdel(arr2);
		*arr2 = 0;
	}
}

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
