/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_dir.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 19:44:42 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/25 17:31:04 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static int	label_ahead(t_parts *start, int to_reach, int current)
{
	int	line;
	int	bytes;

	line = 0;
	bytes = 0;
	while (start && start->line != current)
		start = start->next;
	if (!start)
		error("Label not found", 0);
	while (start && start->line != to_reach)
	{
		if (start->line != line)
		{
			line = start->line;
			bytes += start->line_size;
		}
		start = start->next;
	}
	return (bytes);
}

static int	label_behind(t_parts *start, int to_reach, int current)
{
	int	line;
	int	bytes;

	line = 0;
	bytes = 0;
	while (start && start->line != to_reach)
		start = start->next;
	if (!start)
		error("Label not found", 0);
	while (start && start->line != current)
	{
		if (start->line != line)
		{
			line = start->line;
			bytes += start->line_size;
		}
		start = start->next;
	}
	bytes *= -1;
	return (bytes);
}

/*
**	@desc	- writes a direct argument to the .cor file.
**	@param	- t_parts *start, all the parts of .s file tokenized.
**			- int to_reach, label line towards which instruction sizes will be\
**			- calculated.
**			- int current, label line from which instruction sizes will be\
**			- calcualted.
**	@ret	- difference between current token line and line represented by\
**			- label(to_reach).
*/

int			calculate_lines(t_parts *start, int to_reach, int current)
{
	int	bytes;

	bytes = 0;
	if (current < to_reach)
		bytes = label_ahead(start, to_reach, current);
	else
		bytes = label_behind(start, to_reach, current);
	return (bytes);
}

/*
**	@desc	- writes a direct argument to the .cor file.
**	@param	- t_asm *data, main struct holding output file info and\
**			- parsed assembly.
**			- t_parts *parts, token being written.
**			- int op, operation to which the token belongs.
*/

void		write_dir(t_asm *data, t_parts *token, int op)
{
	int		value;
	int		label_line;
	int		four_bytes;

	if (token->value == MAX_INT)
	{
		label_line = find_label(data->labels, token->name, token->line);
		value = calculate_lines(data->parts, label_line, token->line);
		token->value = value;
	}
	else
		value = token->value;
	if ((op >= 0x01 && op <= 0x08) || op == 0x0d || op == 0x10)
	{
		if (!value)
		{
			write_null_bytes(4, data->wfd);
			return ;
		}
		four_bytes = swap_4_bytes(value);
		write(data->wfd, &four_bytes, 4);
	}
	else
		write_ind(data, token);
}
