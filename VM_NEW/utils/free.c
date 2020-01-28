/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 15:32:44 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 15:40:26 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

void	free_cursors(t_cursor *c)
{
	t_cursor	*temp;

	while (c)
	{
		temp = c->next;
		free(c);
		c = temp;
	}
}

void	free_champs(t_champ *champs, int nb_champs)
{
	int		i;

	i = 0;
	while (i < nb_champs)
	{
		free(champs[i].name);
		free(champs[i].comment);
		i++;
	}
	free(champs);
}

void	free_vm(t_vm *vm)
{
	free_cursors(GAME->cursors);
	free_champs(CHAMPS, NB_PLAYERS);
	free(FLAG);
	free(GAME);
	free(vm);
}
