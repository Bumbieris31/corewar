/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 20:12:01 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/15 20:05:13 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_count(char const *s, char c)
{
	int	i;
	int count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**get_split(char **split, const char *s, char c)
{
	int	i;
	int n;
	int x;

	i = 0;
	x = 0;
	while (i < split_count(s, c))
	{
		n = 0;
		while (s[x] && s[x] == c)
			x++;
		split[i] = ft_strnew(ft_wordlen(&s[x], c) + 1);
		if (split[i] == NULL)
			return (NULL);
		while (s[x] && s[x] != c)
		{
			split[i][n] = s[x];
			n++;
			x++;
		}
		split[i][n] = '\0';
		i++;
	}
	split[i] = NULL;
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char**)malloc(sizeof(char*) * split_count(s, c) + 1);
	if (!split)
		return (NULL);
	split = get_split(split, s, c);
	if (split == NULL)
		return (NULL);
	return (split);
}
