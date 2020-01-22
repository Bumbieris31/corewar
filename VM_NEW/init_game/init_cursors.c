/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cursors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 16:08:42 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 17:26:55 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- prints content of all cursors
**	@param	- t_vm *vm, main struct
*/

static void		cursor_content(t_vm *vm)
{
	t_cursor	*cursor;

	cursor = CURSORS;
	while (cursor)
	{
		ft_printf("\nCursosr id: %d\n", cursor->id);
		ft_printf("champ id: %d \n", cursor->reg[0]);
		ft_printf("Cursor pos: %d\n", cursor->pos);
		ft_printf("Cursor opcode: %d\n", cursor->opcode);
		ft_printf("Next instruction (pc): %d\n", cursor->pc);
		cursor = cursor->next;
	}
}

/*
**	@desc	- function mallocs and sets a cursor
**	@param	- int id, id of player that spawned cursor
**			- int pos, start position of the cursor
**			- int opcode, current operation code of the cursor
**			- int octal, current encoding byte of the cursor
**	@return	- t_cursor *c, freshly malloced cursor
*/

static t_cursor	*set_cursor(int id, int pos, int opcode, int octal)
{
	t_cursor	*c;

	c = ft_memalloc(sizeof(t_cursor));
	if (!c)
		error("Malloc error", NULL);
	c->id = id;
	c->pos = pos;
	c->opcode = opcode;
	c->pc = get_pc(opcode, octal);
	c->wait_cycles = wait_cycle(opcode);
	c->reg[0] = id * -1;
	c->prev_xy[0] = -1;
	c->prev_xy[1] = -1;
	return (c);
}

/*
**	@desc	- initializes game struct
**	@param	- t_vm *vm, main struct
**	@return	- t_game *g, initialized game struct
*/

static t_game	*init_game_struct(t_vm *vm)
{
	t_game	*g;

	g = (t_game*)ft_memalloc(sizeof(t_game));
	if (!g)
		error("Malloc error", NULL);
	g->processes = NB_PLAYERS;
	g->cycles_to_die = CYCLE_TO_DIE;
	g->cycles = 1;
	g->lives = 0;
	return (g);
}

/*
**	@desc	- main function for initialzing cursors
**	@param	- t_vm *vm, main struct
*/

void			init_cursors(t_vm *vm)
{
	t_cursor	*curr;
	int			id;
	int			pos;

	id = NB_PLAYERS;
	GAME = init_game_struct(vm);
	pos = MEM_SIZE - MEM_SIZE / NB_PLAYERS;
	if (MEM_SIZE % NB_PLAYERS)
		pos--;
	CURSORS = set_cursor(id, pos, ARENA[pos], ARENA[pos + 1]);
	curr = CURSORS;
	id--;
	while (id)
	{
		pos -= MEM_SIZE / NB_PLAYERS;
		curr->next = set_cursor(id, pos, ARENA[pos], ARENA[pos + 1]);
		curr = curr->next;
		id--;
	}
	curr->next = NULL;
	cursor_content(vm);
}
