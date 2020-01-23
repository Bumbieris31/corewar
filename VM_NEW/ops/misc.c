/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:20:48 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/23 12:54:46 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function reports live for cursor and possibly player
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	live(t_vm *vm, t_cursor *c, t_args *args)
{
	int		id;

	id = args->value;
	args->value *= -1;
	c->last_live = GAME->cycles;
	if (id >= 1 && id <= NB_PLAYERS)
	{
		CHAMPS[get_player(vm, CHAMPS, id)].lives++;
		CHAMPS[get_player(vm, CHAMPS, id)].last_live = c->last_live;
		GAME->lives++;
	}
}

// void	aff(t_cursor *c, t_args *args);