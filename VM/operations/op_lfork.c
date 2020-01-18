
#include "vm_arena.h"

static int	get_value(t_vm *vm, t_cursor *cursor)
{
	int		value;

	value = convert(&vm->arena[cursor->pos + 1], 2);
	value += cursor->pos;
	value = (value < 0 ? value : value % MEM_SIZE);
	return (value);
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
	new->wait_cycles = get_waite_cycle(new->opcode);
	vm->process++;
	return (true);
}
