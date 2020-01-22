/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:38:16 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 15:54:30 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function places champ in the arena
**	@param	- int *arena, playing field
**			- t_champ champ, champ to be placed
*/

static void	place_champ(t_byte *arena, t_champ champ)
{
	int		i;
	int		pos;

	i = 0;
	pos = champ.start_pos;
	while (i < champ.size)
	{
		arena[pos] = champ.code[i];
		pos++;
		i++;
	}
}

void		print_arena(t_byte *arena)
{
	int		i;

	i = 0;
	ft_putendl("");
	while (i < 23)
	{
		ft_printf("[%.2x]", arena[i]);
		i++;
	}
	ft_putendl("");
}

/*
**	@desc	- function initializes the game field
**	@param	- t_vm *vm, main struct
*/

void		init_game(t_vm *vm)
{
	int		i;

	i = 0;
	ft_bzero(ARENA, MEM_SIZE);
	while (i < NB_PLAYERS)
	{
		place_champ(ARENA, CHAMPS[i]);
		i++;
	}
	dump64(vm);
}
