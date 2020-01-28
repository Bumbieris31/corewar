/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:54:25 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 16:37:42 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

void		n_flag(t_vm *vm, char **av, int ac, int i)
{
	short	idx;

	idx = 0;
	if (i >= ac - 1 || !format_check("%d", av[i + 1]))
		error("-n flag needs numeric value", NULL);
	if (NB_PLAYERS < ft_atoi(av[i + 1]))
		error("value for -n flag larger than number of players ", av[i + 1]);
	while (idx < NB_PLAYERS)
	{
		if (idx == ft_atoi(av[i + 1]) - 1)
			FLAG->play_order[idx] = ft_atoi(av[i + 1]);
		idx++;
	}
}

/*
**	@desc	- function parses the flags
**	@param	- t_vm *vm, main struct
**			- int ac, amount of args
**			- char **av, arguments
*/

void		flags(t_vm *vm, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-dump"))
		{
			if (i >= ac - 1)
				error("-dump flag needs numeric value", NULL);
			if (ft_atoi(av[i + 1]) < 0)
				error("Invalid value for -dump", av[i + 1]);
			FLAG->dump = ft_atoi(av[i + 1]);
		}
		else if (!ft_strcmp(av[i], "-v"))
			FLAG->v = 1;
		else if (!ft_strcmp(av[i], "-n"))
			n_flag(vm, av, ac, i);
		i++;
	}
	i = 0;
	while (i < NB_PLAYERS)
	{
		ft_printf("%d\n", FLAG->play_order[i]);
		i++;
	}
}
