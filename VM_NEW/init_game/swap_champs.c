/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_champs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 15:41:06 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/23 15:43:39 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

void	swap_champs(t_champ *champs, int nb_champs)
{
	t_champ	curr;
	int		i;

	i = 0;
	while (i < nb_champs - 1)
	{
		if (champs[i].id > champs[i + 1].id)
		{
			curr = champs[i];
			champs[i] = champs[i + 1];
			champs[i + 1] = curr;
			i = 0;
		}
		else
			i++;
	}
}
