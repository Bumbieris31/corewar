
#include "vm_arena.h"

bool		op_live(t_cursor *cursor, t_vm *vm)
{
	int		val;

	val = convert(&vm->arena[cursor->pos + 1], 4);
	ft_printf("val %d reg[0] %d\n", val, cursor->reg[0]);
	val *= -1;
	if (cursor && vm)
	{
		if (val == cursor->reg[0] * -1)
		{
			cursor->last_live = vm->current_cycle;
			vm->nbr_lives++;
			vm->last_alive = cursor->reg[0];
			ft_printf("LA: %d\n", vm->last_alive);
			return (true);
		}
	}
	return (false);
}