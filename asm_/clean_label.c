/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_label.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 14:48:34 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/25 14:49:06 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

char	*clean_label(char *label)
{
	char	*new;
	int		i;
	int		j;

	new = ft_strnew(ft_strlen(label));
	i = 0;
	j = 0;
	while (label[i])
	{
		if (ft_strchr(LABEL_CHARS, label[i]))
		{
			new[j] = label[i];
			j++;
		}
		i++;
	}
	return (new);
}
