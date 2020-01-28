/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_ld.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:22:15 by krioliin       #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2020/01/21 18:15:51 by asulliva      ########   odam.nl         */
=======
/*   Updated: 2020/01/23 13:59:30 by krioliin      ########   odam.nl         */
>>>>>>> 07eb134b2a1f6d94ec4ad4e2b05ca1f6bea6649a
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

	// if (!(value == 0 || value == 57672192 || value == 318992387 || value == 436432899 || value == 4294902016 || value == 386101251 ||
	// value == 251883523 || value == 251883523))
	// {
	// 	int imhere = 1;
	// 	imhere++;
	// }

int			get_reg_num(t_vm *vm, int position, e_argctype type)
{
	int		reg_num;
	int		offset;

	offset = 2;
	offset += (type == IND ? 2 : 4);
	reg_num = vm->arena[((position + offset) % MEM_SIZE)];
	return (reg_num);	
}

<<<<<<< HEAD
// int32_t		get_value(t_vm *vm, t_cursor *cursor, e_argctype type)
// {
// 	int32_t	value;
// 	int		offset;
// 	int		size;

// 	offset = 2;
// 	size = (type == IND ? 2 : 4);
// 	value = (int32_t)convert(&vm->arena[cursor->pos + offset], size);
// 	return (value);
// }
static int     swap_32(int nb)
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

long long	get_value(t_vm *vm, t_cursor *cursor, e_argctype type)
=======
long long int		get_value(t_vm *vm, int position, e_argctype type)
>>>>>>> 07eb134b2a1f6d94ec4ad4e2b05ca1f6bea6649a
{
	long long	value;
	int		offset;

	offset = 2;
<<<<<<< HEAD
	value = convert(&vm->arena[cursor->pos + offset], 4);
	if (type == IND)
	{
		value = cursor->pos + (value % IDX_MOD);
		value = swap_32(vm->arena[value + offset]);
=======
	size = (type == IND ? 2 : 4);
	value = convert(&vm->arena[((position + offset) % MEM_SIZE)], size);
	if (type == IND)
	{
		value = position + (value % IDX_MOD);
		value = convert(&vm->arena[(value + offset) % MEM_SIZE], 4);
>>>>>>> 07eb134b2a1f6d94ec4ad4e2b05ca1f6bea6649a
	}
	return (value);
}

bool		op_ld(t_cursor *cursor, t_vm *vm)
{
<<<<<<< HEAD
	e_argctype	args[3];
	int			reg_num;
	int64_t 	value;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	reg_num = get_reg_num(vm, cursor, args[0]);
	value = get_value(vm, cursor, args[0]);
	value = swap_32(value);
	if (!(value == 0 || value == 57672192 || value == 318992387 || value == 436432899 || value == 4294902016 || value == 386101251 ||
	value == 251883523 || value == 251883523 || value == -1))
	{
		int imhere = 1;
		imhere++;
	}
=======
	e_argctype		args[3];
	int				reg_num;
	long long int	value;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	reg_num = get_reg_num(vm, cursor->pos, args[0]);
	value = get_value(vm, cursor->pos, args[0]);
>>>>>>> 07eb134b2a1f6d94ec4ad4e2b05ca1f6bea6649a
	cursor->reg[reg_num - 1] = value;
	cursor->carry = (cursor->reg[reg_num - 1] == 0 ? 1 : 0);
	return (true);
}
