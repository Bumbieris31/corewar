/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_sti.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 14:24:42 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/22 20:54:30 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

// void	visual_st(WINDOW *warena, uint8_t arena[], short id, int address)
// {
// 	int		x;
// 	int		y;
// 	int		pos;
// 	short	i;

// 	i = 0;
// 	wattron(warena, (COLOR_PAIR(id * 10 + 1) | A_DIM));
// 	while (i < 4)
// 	{
// 		pos = address + i;
// 		while (MEM_SIZE <= pos)
// 			pos -= MEM_SIZE;
// 		get_xy_coordinates(&x, &y, pos);
// 		mvwprintw(warena, y, x, "%.2x ", arena[i]);
// 		i++;
// 	}
// 	wrefresh(warena);
// 	wattroff(warena, (COLOR_PAIR(id * 10 + 1) | A_DIM));
// }

void	visual_st(WINDOW *warena, uint8_t arena[MEM_SIZE], short id, int address)
{
	int		x;
	int		y;
	int		pos;
	short	i;

	i = 0;
	wattron(warena, (COLOR_PAIR(id * 10 + 1) | A_DIM));
	while (i < 4)
	{
		pos = address + i;
		while (MEM_SIZE <= pos)
			pos -= MEM_SIZE;
		get_xy_coordinates(&x, &y, pos);
		mvwprintw(warena, y, x, "%.2x ", arena[pos]);
		i++;
	}
	wrefresh(warena);
	wattroff(warena, (COLOR_PAIR(id * 10 + 1) | A_DIM));
}

void	visual_sti(WINDOW *warena, uint8_t arena[MEM_SIZE], short id, int address)
{
	int		x;
	int		y;
	int		pos;
	short	i;

	i = 0;
	wattron(warena, (COLOR_PAIR(id * 10 + 1) | A_DIM));
	while (i < 4)
	{
		pos = address + i;
		while (MEM_SIZE <= pos)
			pos -= MEM_SIZE;
		get_xy_coordinates(&x, &y, pos);
		mvwprintw(warena, y, x, "%.2x ", arena[pos]);
		i++;
	}
	wrefresh(warena);
	wattroff(warena, (COLOR_PAIR(id * 10 + 1) | A_DIM));
}
