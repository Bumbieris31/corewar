/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_arr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 15:55:56 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/06 15:56:19 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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
		if (*arr1)
			free(*arr1);
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
		if (*arr2)
			free(*arr2);
		*arr2 = 0;
	}
}
