/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_champ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:11:54 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 15:22:13 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

static void	champ_start_pos(t_champ *champ, int id, int nb_players)
{
	int	abs_id;
	int	space;

	abs_id = (id < 0 ? id * -1 : id);
	abs_id--;
	space = MEM_SIZE / nb_players;
	champ->start_pos = space * abs_id;
}

static void	champ_id(t_champ *champ, short player_order[MAX_PLAYERS],
		int num)
{
	int		i;
	int		id;
	int		choosen_id;

	i = 0;
	choosen_id = 1;
	id = player_order[num];
	if (id == -1)
	{
		while (id == -1 && i < MAX_PLAYERS)
		{
			if (choosen_id == player_order[i])
			{
				i = -1;
				choosen_id++;
			}
			i++;
		}
		player_order[num] = choosen_id;
		champ->id = choosen_id;
	}
	else
		champ->id = id;
}

void		set_champ(t_champ *champ, short player_order[MAX_PLAYERS],
		int num, int nb_players)
{
	champ_id(champ, player_order, num);
	champ_start_pos(champ, champ->id, nb_players);
}
