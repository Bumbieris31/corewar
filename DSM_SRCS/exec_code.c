/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_code.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 19:39:31 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/02 21:24:47 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc	- function creates a linked list if none present
**			- function appends to linked list if present
**	@param	- t_dsm *data, main struct
**	@return	- t_op *curr, pointer to the end of the list
*/

static t_op	*new_op(t_dsm *data)
{
	t_op	*curr;

	if (data->ops)
	{
		curr = data->ops;
		while (curr && curr->next)
			curr = curr->next;
		curr->next = (t_op*)ft_memalloc(sizeof(t_op));
		return (curr->next);
	}
	else
	{
		data->ops = (t_op*)ft_memalloc(sizeof(t_op));
		curr = data->ops;
		return (curr);
	}
}

/*
**	@desc	- function returns the name of the operation
**	@param	- int op_code, the operation code
**	@toNote	- static char **names keeps its value cause static
**	@return	- string with the name of the operation with a space at the end
*/

static char	*set_name(int op_code)
{
	static char **names = NULL;

	if (!names)
	{
		names = (char**)ft_memalloc(sizeof(char*) * 18);
		names[0] = "wrong \0";
		names[1] = "live \0";
		names[2] = "ld \0";
		names[3] = "st \0";
		names[4] = "add \0";
		names[5] = "sub \0";
		names[6] = "and \0";
		names[7] = "or \0";
		names[8] = "xor \0";
		names[9] = "zjmp \0";
		names[10] = "ldi \0";
		names[11] = "sti \0";
		names[12] = "fork \0";
		names[13] = "lld \0";
		names[14] = "lldi \0";
		names[15] = "lfork \0";
		names[16] = "aff \0";
	}
	return (ft_strdup(names[op_code]));
}

/*
**	@desc	- function finds out what type of arguments are coming
**			- and fills them in accordingly
**	@param	- t_op *curr, the current op
**			- int enc_byte, the encoding byte, already bitshifted (enc_byte >> 2)
**			- use enc_byte to find out what argument types are coming up
**			- int arg_amnt, amount of arguments expected for this operation
**			- int op, the operation code
**	@return	- int size, amount of bytes read
*/

int		find_args(t_op *curr, int enc_byte, int arg_amnt, int op)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	curr->args = (char**)ft_memalloc(sizeof(char*) * arg_amnt + 1);
	while (i < arg_amnt)
	{
		//parse the encoding byte curr->args[i] would be 
		//if 01 curr->args[i] = ft_strdup("r")
		//if 10 curr->args[i] = ft_strdup("%")
		//if 11 curr->args[i] = ft_strdup("")
		//somehow get argument value. size + amount of bytes
		//add , to arg if i < arg_amnt - 1
		i++;
	}
	enc_byte = 0;
	op = 0;
	return (size);
}

/*
**	@desc	- function reads 1 line and parses it
**	@param	- t_dsm *data, main struct
**			- int op, the operation code
**			- int *size, the total size read given as a pointer
*/

void	get_line(t_dsm *data, int op, int *size)
{
	t_op	*new;
	int		ret;
	int		s;

	new = new_op(data);
	new->op_name = set_name(op);
	ft_printf("name is %s\n", new->op_name);
	if (enc_byte(op))
	{
		ret = read(data->rfd, &s, 1);
		*size -= ret;
		*size -= find_args(new, (s >> 2), arg_amnt(op), op);
	}
	else
		*size -= find_args(new, 0, arg_amnt(op), op);
}

/*
**	@desc	- main function in extracting the exec code from the file
**	@param	- t_dsm *data, main struct
*/

void	get_exec_code(t_dsm *data)
{
	int	s;
	int	ret;
	int	size;

	ret = 1;
	size = data->size;
	while (ret)
	{
		s = 0;
		ret = read(data->rfd, &s, 1);
		size -= ret;
		if (s < 1 || s > NB_OPS)
			ft_printf("%#X is NOT\n", s);
		else
			get_line(data, s, &size);
	}
	if (size)
		error("Size of champion does not match", 0);
}
