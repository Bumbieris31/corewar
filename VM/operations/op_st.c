
#include "vm_arena.h"

static int	get_reg_num(t_vm *vm, t_cursor *cursor)
{
	int		offset;
	int		reg_num;

	offset = 2;
	reg_num = vm->arena[cursor->pos + offset];
	if (reg_num <= 0)
		return (1);
	return (reg_num);
}

static void	write_value(t_vm *vm, t_cursor *cursor, e_argctype type, int32_t value)
{
	int	index;
	int	offset;
	int	address;

	offset = 3;
	if (type == REG)
	{
		index = vm->arena[cursor->pos + offset] - 1;
		cursor->reg[index] = value;
	}
	else if (type == IND)
	{
		index = convert(&vm->arena[cursor->pos + offset], 2);
		if (index == 15)
		{
			ft_printf("");
		}
		index %= IDX_MOD;
		address = cursor->pos + index;
		// while (address < 0)						// new
		// 	address = MEM_SIZE + address;		// new
		address = (address < 0 ? address + MEM_SIZE : address % MEM_SIZE);
		write_into_memory(value, vm->arena, address);
		if (vm->flag->v)
			visual_st(vm->v->warena, &(vm->arena[address]), cursor->id, address);
	}
}

int     swap_32(int nb)
{
    int b1;
    int b2;
    int b3;
    int b4;
    b1 = (nb & 0x000000ff) << 24;
    b2 = (nb & 0x0000ff00) << 8;
    b3 = (nb & 0x00ff0000) >> 8;
    b4 = (nb & 0xff000000) >> 24;
    return (b1 | b2 | b3 | b4);
}

bool		op_st(t_cursor *cursor, t_vm *vm)
{
	e_argctype		args[3];
	int				reg_num;
	long long int	value;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	reg_num = get_reg_num(vm, cursor);
	value = swap_32(cursor->reg[reg_num - 1]);
	if (!(value == 0 || value == 57672192 || value == 318992387 || value == 436432899 || value == 4294902016 || value == 386101251 ||
	value == 251883523 || value == 251883523))
	{
		int imhere = 1;
		imhere++;
	}
	if (0 < value)
		ft_printf("");
	write_value(vm, cursor, args[1], value);
	return (true);
}
