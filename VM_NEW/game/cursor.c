/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 19:08:18 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/23 13:52:07 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function copies cursor
**	@param	- t_cursor *src, cursor to be copied
**			- int pos, position of new cursor
**			- long id, id of parent cursor
**	@return	- t_cursor *new, copied cursor
*/

t_cursor	*cp_cursor(t_cursor *src, int pos, long id)
{
	t_cursor	*new;

	new = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	ft_memcpy(new, src, sizeof(t_cursor));
	new->pos = pos;
	new->id = id;
	return (new);
}

/*
**  @desc   - function moves cursor to new location
**  @param  - t_vm *vm, main struct
**			- t_cursor *c, cursor to move
**			- int move, amount to move
*/

void		mv_cursor(t_vm *vm, t_cursor *c, int move)
{
	int old_pos;

	old_pos = c->pos;
	c->pos = get_index(old_pos, move);
	if (FLAG->v)
		;
}

void		add_cursor(t_cursor **head, t_cursor *new)
{
	if (!head)
		return ;
	new->next = *head;
	*head = new;
}
