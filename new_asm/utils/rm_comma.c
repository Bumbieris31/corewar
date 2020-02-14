/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rm_comma.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:52:25 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/14 21:35:06 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- function removes SEPARATOR_CHAR (standard ',') from a string
**	@param	- char *s, string which might have SEPARATOR_CHAR
**	@return	- char *new, new string without SEPARATOR_CHAR
*/

char		*rm_comma(char *s)
{
	char	*new;
	int		i;
	int		count;																	// NOT USED

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
	return (new);
}
