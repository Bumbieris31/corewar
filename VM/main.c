/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/08 19:09:42 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

void	init_vm(t_vm *vm)
{
	vm->process = vm->players_amnt;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->last_alive = vm->players[0]->id * -1;
}

int		main(int argc, char **argv)
{
	t_vm		*vm;

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		return (0);
	if (!(vm->flag = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (0);
	if (!args_validation(argc, argv, vm->flag))
		parse_error();
	else if (!init_players(vm))
		ft_printf("Can't init players\n");
	else if (!init_battlefield(vm))
	{
		vm_free(&vm);
		return (0);
	}
	else if (!init_cursors(vm))
		ft_printf("Error in cursor init\n");
	init_vm(vm);
	start_game(vm);
	if (vm->flag->v)
		visual_corawar(vm);
	vm_free(&vm);
	return (0);
}
