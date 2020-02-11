/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rm_comma.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:52:25 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/11 19:10:15 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- function removes SEPARATOR_CHAR (standard ',') from a string
**	@param	- char *s, string which might have SEPARATOR_CHAR
**	@return	- char *new, new string without SEPARATOR_CHAR
*/

char		*rm_comma(char *s, int line)
{
	char	*new;
	int		i;
	int		count;

	new = ft_strdup(s);
	i = 0;
	count = 0;
	while (new[i])
	{
		if (new[i] == SEPARATOR_CHAR)
		{
			count++;
			new[i] = '\0';
		}
		i++;
	}
	line = 0;
	return (new);
}
