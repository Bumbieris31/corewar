/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 16:38:56 by asulliva       #+#    #+#                */
<<<<<<< HEAD:dsm_/free.c
/*   Updated: 2020/01/30 15:13:17 by krioliin      ########   odam.nl         */
=======
/*   Updated: 2020/02/23 14:38:53 by asulliva      ########   odam.nl         */
>>>>>>> aidan:dsm_/free.c
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc	- function frees the exec code (t_op struct)
**	@param	- t_op *ops, the LL of operations
*/

<<<<<<< HEAD:dsm_/free.c
static void	free_ops(t_oop *ops)
{
	t_oop	*temp;
=======
static void	free_ops(t_oper *ops)
{
	t_oper	*temp;
>>>>>>> aidan:dsm_/free.c

	while (ops)
	{
		temp = ops->next;
		free_arr(&(ops->op_name), &(ops->args), 2);
		free(ops);
		ops = temp;
	}
	free(ops);
	free(temp);
}

/*
**	@desc	- main free function
**	@param	- t_dsm *data, struct to be freed
*/

void		free_all(t_dsm *data)
{
	free_ops(data->ops);
	free(data->comment);
	free(data->name);
	free(data);
}
