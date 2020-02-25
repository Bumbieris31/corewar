/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   encoding_byte.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 16:58:59 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/25 17:22:06 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static void	add_reg(char *enc, int argc)
{
	char	reg;

	reg = 1;
	*enc = *enc | (reg << argc * 2);
}

static void	add_dir(char *enc, int argc)
{
	char	dir;

	dir = 2;
	*enc = *enc | (dir << argc * 2);
}

static void	add_ind(char *enc, int argc)
{
	char	ind;

	ind = 3;
	*enc = *enc | (ind << argc * 2);
}

/*
**	@desc	- encodes a byte based on the arguments operation has
**	@param	- t_parts *oper,
*/

char		encoding_byte(t_parts *oper)
{
	int		line;
	char	enc;
	int		i;
	t_parts	*curr;

	i = 4;
	enc = 0;
	line = oper->line;
	curr = oper;
	while (curr && line == curr->line)
	{
		if (curr->token == REG)
			add_reg(&enc, i);
		if (curr->token == DIR)
			add_dir(&enc, i);
		if (curr->token == IND)
			add_ind(&enc, i);
		curr = curr->next;
		i--;
	}
	return (enc);
}
