/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_lfork.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 14:12:28 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/23 14:52:37 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

static int	get_value(t_vm *vm, int position)
{
	int		value;

<<<<<<< HEAD
	value = convert(&vm->arena[cursor->pos + 1], 2);
	value += cursor->pos;
	return (value);
=======
	value = convert(&vm->arena[(position + 1) % MEM_SIZE], 2);
	value += position;
	value = (value < 0 ? MEM_SIZE + value : value);
	while (MEM_SIZE <= value)
		value -= MEM_SIZE;
	return (value % MEM_SIZE);
>>>>>>> 07eb134b2a1f6d94ec4ad4e2b05ca1f6bea6649a
}

static void	cp_regs(t_cursor *new, int32_t reg[16])
{
	int		i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = reg[i];
		i++;
	}
}

bool		op_lfork(t_cursor *cursor, t_vm *vm)
{
	int			new_pc;
	t_cursor	*new;

<<<<<<< HEAD
	new_pc = get_value(vm, cursor);
	new = init_cursor(cursor->id, cursor->pos, cursor->opcode, vm->arena[cursor->pos + 1]);
	cp_regs(new, cursor->reg);
	new->last_live = cursor->last_live;
	new->carry = cursor->carry;
	insert_to_end(cursor, new);
	new->pos += new_pc;
	new->pos %= MEM_SIZE;
	new->opcode = vm->arena[new->pos];
	new->pc =
	calculate_program_counter(new->opcode, vm->arena[new->pos + 1]);
=======
	new_pc = get_value(vm, cursor->pos);
	new = init_cursor(cursor->id, new_pc, cursor->opcode, 0);
	new->last_live = cursor->last_live;
	new->carry = cursor->carry;
	cp_regs(new, cursor->reg);
	insert_new(new, vm);
	new->pos += new_pc;
	while (MEM_SIZE <= new->pos)
		new->pos -= MEM_SIZE;
	new->opcode = vm->arena[new->pos];
	new->pc =
	calculate_program_counter(new->opcode, vm->arena[(new->pos + 1) % MEM_SIZE]);
>>>>>>> 07eb134b2a1f6d94ec4ad4e2b05ca1f6bea6649a
	new->wait_cycles = get_waite_cycle(new->opcode);
	vm->process++;
	return (true);
}
