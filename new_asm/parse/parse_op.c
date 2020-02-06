/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_op.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:26:27 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/06 17:10:49 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- make new instruction object
**	@param	- int token, token of the new instruction/argument
**			- int line, line number of new object
**	@return	- new parts object
*/

t_parts		*make_instruction(int token, int line, char *s)
{
	t_parts	*new;

	new = malloc(sizeof(t_parts));
	new->token = token;
	if (new->token < 0)
		new->value = get_value(token, line, s);
	else
		new->value = 0;
	new->line = line;
	new->size = 0;
	new->line_size = 0;
	new->name = rm_comma(s, line);
	new->next = NULL;
	return (new);
}

/*
**	@desc	- function adds new instruction to linked list
**	@param	- t_asm *data, main struct
**			- t_parts *new, instruction object to be added
*/

void		add_instruction(t_asm *data, t_parts *new)
{
	t_parts	*curr;

	curr = data->parts;
	if (!curr)
	{
		data->parts = new;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

/*
**	@desc	- function parse an instruction line
**	@param	- t_asm *data, main struct
**			- char **line, line split on whitespace
*/

void		parse_instruction(t_asm *data, char **line)
{
	t_parts	*new;
	int		i;

	i = 0;
	while (line[i])
	{
		new = make_instruction(get_token(line[i]), data->lines, line[i]);
		add_instruction(data, new);
		i++;
	}
}
