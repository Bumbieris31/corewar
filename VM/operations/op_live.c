/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_live.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:44:31 by krioliin       #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2020/01/10 19:17:07 by krioliin      ########   odam.nl         */
=======
/*   Updated: 2020/01/10 18:58:57 by asulliva      ########   odam.nl         */
>>>>>>> aidan
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool		op_live(t_cursor *cursor, t_vm *vm)
{
	int		val;

	val = convert(&vm->arena[cursor->pos + 1], 4);
	ft_printf("val %d reg[0] %d\n", val, cursor->reg[0]);
	if (val == cursor->reg[0])
	{
		cursor->last_live = vm->current_cycle;
		vm->nbr_lives++;
		vm->last_alive = cursor->reg[0];
		ft_printf("LA: %d\n", vm->last_alive);
	}
	return (true);
}
