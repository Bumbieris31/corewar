/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:20:54 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/23 12:53:40 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function loads value into cursor registry
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	ld(t_vm *vm, t_cursor *c, t_args *args)
{
	t_args	a1;
	int		reg_nb;

	a1 = args[0];
	reg_nb = args[1].value - 1;
	if (a1.type == IND)
		c->reg[reg_nb] = get_bytes(ARENA, get_index(c->pos,
		(a1.value % IDX_MOD)), 4);
	else if (a1.type == DIR)
		c->reg[reg_nb] = a1.value;
	c->carry = (c->reg[reg_nb] == 0 ? 1 : 0);
}

// void	ldi(t_vm *vm, t_cursor *c, t_args *args);
// void	lld(t_vm *vm, t_cursor *c, t_args *args);
// void	lldi(t_vm *vm, t_cursor *c, t_args *args);
