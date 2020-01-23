/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:20:58 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/23 12:58:58 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function stores value dest dependent on a2.value
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	st(t_vm *vm, t_cursor *c, t_args *args)
{
	int		index;
	int		val;
	t_args	a1;
	t_args	a2;

	a1 = args[0];
	a2 = args[1];
	if (a2.type == REG)
		c->reg[a2.value - 1] = c->reg[a1.value - 1];
	else if (a2.type == IND)
	{
		val = swap_32(c->reg[a1.value - 1]);
		index = get_index(c->pos, (a2.value % IDX_MOD));
		put_value(ARENA, index, &val);
		if (FLAG->v)
			;
	}
}

// void	sti(t_vm *vm, t_cursor *c, t_args *args);
