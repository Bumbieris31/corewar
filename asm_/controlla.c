/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controlla.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 14:34:26 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/05 15:48:48 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static int	check_instruction2(char *s)
{
	if (ft_strequ(s, "zjmp"))
		return (ZJMP);
	else if (ft_strequ(s, "ldi"))
		return (LDI);
	else if (ft_strequ(s, "sti"))
		return (STI);
	else if (ft_strequ(s, "fork"))
		return (FORK);
	else if (ft_strequ(s, "lld"))
		return (LLD);
	else if (ft_strequ(s, "lldi"))
		return (LLDI);
	else if (ft_strequ(s, "lfork"))
		return (LFORK);
	else if (ft_strequ(s, "aff"))
		return (AFF);
	return (0x00);
}

/*
**	@desc	- function checks if string is an instruction
**	@param	- char *s, string to check
**	@return	- returns > 0 if instruction
**			- returns 0 if not an instruction
*/

int			check_instruction(char *s)
{
	if (ft_strchr(s, LABEL_CHAR))
		return (0x00);
	if (ft_strequ(s, "live"))
		return (LIVE);
	else if (ft_strequ(s, "ld"))
		return (LD);
	else if (ft_strequ(s, "st"))
		return (ST);
	else if (ft_strequ(s, "add"))
		return (ADD);
	else if (ft_strequ(s, "sub"))
		return (SUB);
	else if (ft_strequ(s, "and"))
		return (AND);
	else if (ft_strequ(s, "or"))
		return (OR);
	else if (ft_strequ(s, "xor"))
		return (XOR);
	else
		return (check_instruction2(s));
}

int			find_label(t_label *label, char *name, int line)
{
	char *clean;

	clean = clean_label(name);
	while (label && ft_strcmp(clean, label->name))
		label = label->next;
	free(clean);
	if (!label)
		error("Label not found", line);
	return (label->line);
}
