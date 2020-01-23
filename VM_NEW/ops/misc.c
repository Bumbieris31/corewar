/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:20:48 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/23 13:46:33 by asulliva      ########   odam.nl         */
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

/*
**	@desc	- function takes value from reg and 
**	@param	- t_cursor *c, current cursor
**			- t_args *args, arguments print (char)value
*/

void	aff(t_cursor *c, t_args *args)
{
	char	c;
	int		reg_nb;

	reg_nb = args[0].value - 1;
	c = (char)c->reg[reg_nb];
	write(1, &c, 1);
}
