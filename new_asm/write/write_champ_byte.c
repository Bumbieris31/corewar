/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_champ_byte.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:33:41 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/20 16:03:53 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		write_reg(int value, int wfd)
{
	char	reg;

	reg = (char)value;
	if (!reg)
		write(wfd, "\0", 1);
	else
		write(wfd, &reg, 1);
}

void			write_ind(t_asm *data, t_parts *token)
{
	int		label_line;
	short	ind;
	short	swap;

	if (token->value == MAX_INT)
	{
		ft_printf("token->name %s\n", token->name);
		label_line = find_label(data->labels, token->name, token->line);
		ind = (short)calculate_lines(data->parts, label_line, token->line);
	}
	else
		ind = (short)token->value;
	if (!ind)
	{
		write_null_bytes(2, data->wfd);
		return ;
	}
	swap = swap_2_bytes(ind);
	write(data->wfd, &swap, 2);
}

static t_parts	*write_line(t_asm *data, t_parts *parts)
{
	int	op;
	int	line;

	op = parts->token;
	line = parts->line;
	parts = parts->next;
	while (parts && line == parts->line)
	{
		if (parts->token == REG)
			write_reg(parts->value, data->wfd);
		else if (parts->token == IND)
			write_ind(data, parts);
		else if (parts->token == DIR)
			write_dir(data, parts, op);
		parts = parts->next;
	}
	return (parts);
}

/*
**	Assumes that the *parts list starts with an operation and
**	the syntax is correct
*/

void			write_champ_byte(t_asm *data)
{
	char	op;
	char	enc;
	t_parts	*parts;

	parts = data->parts;
	while (parts)
	{
		op = parts->token;
		write(data->wfd, &op, 1);
		if (op != 0x01 && op != 0x09 && op != 0x0c && op != 0x0f)
		{
			enc = encoding_byte(parts);
			write(data->wfd, &enc, 1);
		}
		parts = write_line(data, parts);
	}
}
