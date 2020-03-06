/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_syntax.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 18:06:37 by abumbier       #+#    #+#                */
/*   Updated: 2020/03/06 20:21:31 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@desc	- main controller function for checking the syntax and arguments
**	@param	- t_parts file, tokenized file
*/

void		check_syntax(t_asm *data)
{
	int		invalid;
	t_parts	*token;

	token = data->parts;
	invalid = 0;
	while (token)
	{
		if (token->token >= LIVE && token->token <= AFF)
			if (!valid_oper_line(&token))
			{
				invalid = 1;
				break ;
			}
	}
	if (invalid)
	{
		free_data(data);
		exit(1);
	}
}
