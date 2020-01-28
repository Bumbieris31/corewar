/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:28:07 by asulliva       #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2020/01/21 19:21:48 by asulliva      ########   odam.nl         */
=======
/*   Updated: 2020/01/25 19:29:08 by krioliin      ########   odam.nl         */
>>>>>>> 07eb134b2a1f6d94ec4ad4e2b05ca1f6bea6649a
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vm_arena.h"

int		bury_dead_cursors(t_cursor **head, t_vm *vm)
{
	int			corpse_counter;
	t_cursor	*cursor;
	t_cursor	*prev;

	prev = *head;
	corpse_counter = 0;
	while (prev && prev->last_live == 0)
	{
		*head = prev->next;
		ft_memdel((void **)&prev);
		if (*head == NULL)
			return (100);
		prev = *head;
		corpse_counter++;
	}
	prev->last_live = 0;
	cursor = prev->next;
	while (cursor)
	{
		if (cursor->last_live <= 0)
		{
			if (vm->flag->v)
				show_corpse(cursor->id, vm->v->wop);
			prev->next = cursor->next;
			ft_memdel((void **)&cursor);
			corpse_counter++;
			if (prev == NULL)
				break ;
		}
		else
			cursor->last_live = 0;
		prev = prev->next;
		if (prev == NULL)
			break ;
		cursor = prev->next;
	}
	return(corpse_counter);
}

bool	check(t_vm *vm)
{
	static int checks_in_row;

	checks_in_row++;
	if (NBR_LIVE <= vm->nbr_lives || MAX_CHECKS <= checks_in_row)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		checks_in_row = 0;
		if (vm->flag->v)
			refresh_cycle_to_die(vm->v->winfo, 29, vm->cycle_to_die);
	}
	vm->nbr_lives = 0;
	vm->process -= bury_dead_cursors(&vm->cursor, vm);
	return (0 < vm->process);
}

bool	execute_one_cycle(t_vm *vm)
{
	t_cursor	*cursor;

	cursor = vm->cursor;
	while (cursor)
	{
		execute_cursor(cursor, vm->arena, vm);
		cursor = cursor->next;
	}
	if (vm->flag->v)
		refresh_arena(vm);
	return (true);
}

bool	up_to_cycle_to_die(t_vm *vm)
{
	bool		someone_alive;
<<<<<<< HEAD
	static int	cycle;
=======
>>>>>>> 07eb134b2a1f6d94ec4ad4e2b05ca1f6bea6649a

	someone_alive = true;
	while (someone_alive && 0 < vm->cycle_to_die)
	{
		while (vm->current_cycle <= vm->cycle_to_die)
		{
			execute_one_cycle(vm);
<<<<<<< HEAD
			cycle++;
			vm->current_cycle += 1;
			if (vm->flag->hexdump == cycle)
				return (show_arena(vm->players, vm->players_amnt, vm));
			else if (vm->flag->dump == cycle)
=======
			vm->cycle_counter += 1;
			vm->current_cycle += 1;
			if (vm->flag->hexdump == vm->cycle_counter)
				return (show_arena(vm->players, vm->players_amnt, vm));
			else if (vm->flag->dump == vm->cycle_counter)
>>>>>>> 07eb134b2a1f6d94ec4ad4e2b05ca1f6bea6649a
				return (dump64(vm));
		}
		vm->current_cycle = 0;
		someone_alive = check(vm);
		discard_players_lives_calls(vm);
	}
	return (true);
}

// bool	start_game(t_vm *vm)
// {
// 	t_player *the_champion;

// 	if (up_to_cycle_to_die(vm))
// 	{
// 		the_champion = get_player_by_id(vm->players, vm->last_alive, vm->players_amnt);
// 		if (vm->flag->v == true)
// 			congrats_champion(vm->v->wop, the_champion);
// 		else
// 			ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_alive, the_champion->name);
// 	}
// 	return (true);
// }

void	check_octal(t_vm *vm, t_cursor *c, int octal)
{
	int		i;
	int		size;
	t_args	*args;

	
}

void	cursor(t_vm *vm, t_cursor *c)
{
	t_args	*args;
	int		size;

	ft_printf("c->opcode %#x\n", c->opcode);
	if (is_encoding_byte(c->opcode))
		check_octal(vm, c, vm->arena[(c->pos + 1) % MEM_SIZE]);
	else
	{
		args = ft_memalloc(sizeof(t_args));
		args->size = get_dir_size(c->opcode);
		size = args->size + 1;
		args->value = convert(&vm->arena[c->pos + 1], args->size);
		args->type = DIR;
		//do operation
	}
	
}

void	execute(t_vm *vm)
{
	t_cursor	*curr;

	curr = vm->cursor;
	while (curr)
	{
		cursor(vm, curr);
		curr = curr->next;
	}
	if (vm->flag->v)
		refresh_arena(vm);
}

bool	game_loop(t_vm *vm)
{
	bool	alive;
	int		cycle;

	alive = true;
	cycle = 0;
	while (alive && 0 < vm->cycle_to_die)
	{
		while (vm->current_cycle <= vm->cycle_to_die)
		{
			execute(vm);
			vm->current_cycle += 1;
			cycle++;
			if (vm->flag->hexdump == cycle)
				return (show_arena(vm->players, vm->players_amnt, vm));
			else if (vm->flag->dump == cycle)
				return (dump64(vm));
		}
		vm->current_cycle = 0;
		vm->cycles_passed++;
		alive = check(vm);
		discard_players_lives_calls(vm);
	}
	return (true);
}

bool	start_game(t_vm *vm)
{
	t_player	*champ;

	if (game_loop(vm))
	{
		champ = get_player_by_id(vm->players, vm->last_alive, vm->players_amnt);
		if (vm->flag->v == true)
			congrats_champion(vm->v->wop, champ);
		else
			ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_alive, champ->name);
	}
	return (true);
}