/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_live_calls.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 18:52:49 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/18 21:11:25 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

void	display_live_calls_init(WINDOW *winfo, short player_amnt)
{
	int		i;

	i = 1;
	while (i <= player_amnt)
	{
		wattron(winfo, COLOR_PAIR(i));
		mvwprintw(winfo, OFFSETY + i * 4 + 2, 32, "%d", 0);
		mvwprintw(winfo, OFFSETY + i * 4 + 1, 32, "%d", 0);
		i++;
	}
}

void	display_live_calls(WINDOW *winfo, t_player *player, int cycles_passed)
{
	wattron(winfo, COLOR_PAIR(player->id));
	mvwprintw(winfo, OFFSETY + player->id * 4 + 1, 32, "%d",
	player->last_live + CYCLE_TO_DIE * cycles_passed);
	mvwprintw(winfo, OFFSETY + player->id * 4 + 2, 32, "%d", player->lives);
	wrefresh(winfo);
}
