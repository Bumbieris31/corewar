/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 14:33:38 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 14:57:39 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function calculates the pc (jump to next op)
**	@param	- int opcode, operation code
**			- int octal, encoding byte
**	@return	- number of bytes to jump to next operation
*/

int		get_pc(int opcode, int octal)
{
	int			pc;
	e_argctype	args[3];

	pc = 0;
	if (g_op_tab[opcode].octal == 1)
	{
		decode(octal, args);
		pc += arg_size(args[0], opcode);
		pc += arg_size(args[1], opcode);
		pc += arg_size(args[2], opcode);
		return (pc + 2);
	}
	else if (opcode == LIVE)
		pc = 4;
	else if (opcode == ZJMP || opcode == FORK || opcode == LFORK)
		pc = 2;
	return (pc + 1);
}