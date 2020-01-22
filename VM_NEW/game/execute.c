/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 17:55:13 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 17:57:39 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

void	execute_op(t_vm *vm, t_cursor *c)
{

}

void	execute(t_vm *vm)
{
	t_cursor	*c;

	c = CURSORS;
	while (c)
	{
		execute_op(vm, c);
		c = c->next;
	}
}