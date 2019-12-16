/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:41:45 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/16 19:04:49 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_size(t_parts *parts, int wfd)
{
	int		line;
	int		size; //num of bytes
	t_parts	*curr_oper;

	while (parts)
	{
		line = parts->line;
		curr_oper = parts;
		while (parts && line == parts->line)
		{
			// curr_oper->token value (oper code) will determine T_DIR value here;
		}
	}
}