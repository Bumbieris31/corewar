/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:24:02 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 17:27:31 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

/*
**	@desc	- function initializes main struct
*/

static t_vm	*init(void)
{
	t_vm	*new;

	new = ft_memalloc(sizeof(t_vm));
	new->flag = ft_memalloc(sizeof(t_flags));
	if (!new || !new->flag)
		error("Malloc error", NULL);
	return (new);
}

int			main(int ac, char **av)
{
	t_vm	*vm;

	vm = init();
	parse_args(ac, av, vm->flag);
	parse_champs(vm);
	init_game(vm);
	dump64(vm);
	start_game(vm);
}
