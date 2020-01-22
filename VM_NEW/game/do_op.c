/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_op.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 20:03:39 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 20:14:30 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- followup for main controller for operations
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

static void		do_op2(t_vm *vm, t_cursor *cursor, t_args *args)
{
	int	opcode;

	opcode = cursor->opcode;
	if (opcode == ZJMP)
		zjmp(vm, cursor, args);
	else if (opcode == LDI)
		ldi(vm, cursor, args);
	else if (opcode == STI)
		sti(vm, cursor, args);
	else if (opcode == FORK)
		op_fork(vm, cursor, args, IDX_MOD);
	else if (opcode == LLD)
		lld(vm, cursor, args);
	else if (opcode == LLDI)
		lldi(vm, cursor, args);
	else if (opcode == LFORK)
		op_fork(vm, cursor, args, MEM_SIZE);
	else if (opcode == AFF)
		aff(cursor, args);
}

/*
**	@desc	- main controller for operations
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
**			- int size, size to jump if no opcode
*/

void	do_op(t_vm *vm, t_cursor *c, t_args *args, int size)
{
	int	opcode;

	opcode = c->opcode;
	if (opcode == LIVE)
		live(vm, c, args);
	else if (opcode == LD)
		ld(vm, c, args);
	else if (opcode == ST)
		st(vm, c, args);
	else if (opcode == ADD)
		add(c, args);
	else if (opcode == SUB)
		sub(c, args);
	else if (opcode == AND)
		and(vm, c, args);
	else if (opcode == OR)
		or(vm, c, args);
	else if (opcode == XOR)
		xor(vm, c, args);
	else
		do_op_2(vm, c, args);
	if (opcode != ZJMP || (opcode == ZJMP && !c->carry))
		move_c(vm, c, size);
	free(args);
}