/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_syntax.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 18:06:37 by abumbier       #+#    #+#                */
/*   Updated: 2020/02/13 17:04:23 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- main controller function for checking the syntax and arguments
**	@param	- t_parts file, tokenized file
*/

void		check_syntax(t_parts *file)
{
	t_parts *token;

	token = file;
	while (token)
	{
		if (token->token >= LIVE && token->token <= AFF)
			if (!valid_oper_line(&token))
				break ;
	}
	//if (!valid_oper_line)
	//{
	//	free_data();
	//}
	// exit if valid_oper_line is 0
}
