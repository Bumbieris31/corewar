/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_size.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 18:41:45 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/12 20:52:26 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@descr	- Determines the type of arguments for one line and sums them.
**	@param	- int op, checks which operation and dir arg combinations add\
**			- 2 and 4 bytes.
*/

static int	arg_sizes(t_parts **parts, int op)
{
	int	line;
	int	arg_size;

	arg_size = 0;
	line = (*parts)->line;
	*parts = (*parts)->next;
	while (*parts && line == (*parts)->line)
	{
		if ((*parts)->token == REG)
			arg_size++;
		else if ((*parts)->token == IND)
			arg_size += 2;
		else if ((*parts)->token == DIR)
		{
			if ((op >= 0x01 && op <= 0x08) || op == 0x0d || op == 0x10)
				arg_size += 4;
			else
				arg_size += 2;
		}
		*parts = (*parts)->next;
	}
	return (arg_size);
}

/*
**	@descr	- Sums the size of all the lines.
*/

static int	line_sizes(t_parts *parts)
{
	int		op;
	int		size;
	t_parts	*curr_oper;

	size = 0;
	while (parts)
	{
		curr_oper = parts;
		op = curr_oper->token;
		curr_oper->line_size++;
		if (op != 0x01 && op != 0x09 && op != 0x0c && op != 0x0f)
			curr_oper->line_size++;
		curr_oper->line_size += arg_sizes(&parts, op);
		size += curr_oper->line_size;
	}
	return (size);
}

/*
**	@desc	- Writes the size of assembled champ code to the .cor file.
**	@param	- t_parts *parts, all the tokenized champ code parts.
**			- int wfd, file descriptor for writing.
*/

void		write_size(t_parts *parts, int wfd)
{
	int	size;
	int	write_size;

	size = line_sizes(parts);
	write_size = swap_4_bytes(size);
	write(wfd, &write_size, 4);
}
