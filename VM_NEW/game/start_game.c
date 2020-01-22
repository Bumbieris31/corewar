/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 17:27:58 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 17:54:56 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function kills dead cursors and returns amount it killed
**	@param	- t_cursor **head, pointer to head of linked list cursors
**	@return	- nb of processes killed
*/

static int	dead_cursors(t_cursor **head)
{
	int			body_count;
	t_cursor	*curr;
	t_cursor	*prev;

	prev = *head;
	body_count = 0;
	while (prev && !prev->last_live)
	{
		*head = prev->next;
		ft_memdel((void**)&prev);
		prev = *head;
		body_count++;
	}
	prev->last_live = 0;
	curr = prev->next;
	while (curr)
	{
		if (curr->last_live <= 0)
		{
			prev->next = curr->next;
			ft_memdel((void**)&curr);
			body_count++;
		}
		else
			curr->last_live = 0;
		prev = prev->next;
		if (!prev)
			break ;
		curr = prev->next;
	}
	return (body_count);
}

/*
**	@desc	- funtion checks if there are still processes alive
**	@param	- t_vm *vm, main struct
**	@return	- 1 if still processes, 0 if not
*/

static int	check_live(t_vm *vm)
{
	static int	nb_checks;

	nb_checks++;
	if (NBR_LIVE <= GAME->lives || MAX_CHECKS <= nb_checks)
	{
		GAME->cycles_to_die -= CYCLE_DELTA;
		nb_checks = 0;
	}
	GAME->lives = 0;
	GAME->processes -= dead_cursors(&CURSORS);
	return (0 < GAME->processes);
}

/*
**	@desc	- main game loop
**	@param	- t_vm *vm, main struct
**	@return	- returns 1 when done
*/

static int	game_loop(t_vm *vm)
{
	int		alive;
	int		cycle;

	alive = 1;
	cycle = 0;
	while (alive && 0 < GAME->cycles_to_die)
	{
		while (GAME->cycles <= GAME->cycles_to_die)
		{
			execute(vm);
			cycle++;
			GAME->cycles++;
			if (FLAG->dump == cycle)
				return (dump64(vm));
		}
		GAME->cycles = 0;
		GAME->nb_ctd++;
		alive = check_live(vm);
	}
	return (1);
}

/*
**	@desc	- function starts and ends the game
**	@param	- t_vm *vm, main struct
*/

void		start_game(t_vm *vm)
{
	t_champ	*champ;

	if (game_loop(vm))
	{
		champ = get_player(CHAMPS, GAME->last_live, NB_PLAYERS);
		ft_printf("Contestant %d, \"%s\", has won !\n", GAME->last_live, champ->name);
	}
}