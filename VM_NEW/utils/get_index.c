/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_index.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 18:55:54 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/26 16:13:44 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function return actual index
**	@param	- int current, current index
**			- int move, how many bytes to move
**	@return	- int current, the new index
*/

int		get_index(int current, int move)
{
	if (move >= 0)
		return ((current + move) % MEM_SIZE);
	current += move;
	ft_printf("current %d\n", current);
	if (current < 0)
		return (MEM_SIZE + current);
	return (current);
}
