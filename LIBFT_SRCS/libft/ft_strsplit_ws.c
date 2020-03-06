/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit_ws.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 16:36:48 by abumbier       #+#    #+#                */
/*   Updated: 2020/03/06 18:29:45 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*MOVE TO HEADER*/																	//		CMD X
#define SPACE	32
#define TAB		9
#define COMMA	44

int			count_words(char const *s)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != SPACE || s[i] != TAB || s[i] != COMMA) && \
		(s[i + 1] == SPACE || s[i + 1] == TAB || \
		s[i + 1] == COMMA || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_strsplit_end(char **arr, int y)
{
	arr[y] = NULL;
	return (arr);
}

static int	findchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}


int			find_ws(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == SPACE || s[i] == TAB || s[i] == COMMA)
			return (i);
		i++;
	}
	return (-1);
}

char		**ft_strsplit_ws(char const *s)
{
	size_t	i;
	int		y;
	char	**arr;
	int		end;
	int		word_c;

	y = 0;
	i = 0;
	word_c = count_words(s);
	arr = s ? (char **)malloc(word_c * sizeof(char *) + 1) : 0;
	if (arr == NULL || arr == 0)
		return (NULL);
	while (s[i] && y < word_c)
	{
		while (s[i] == SPACE || s[i] == TAB || s[i] == COMMA)
			i++;
		end = find_ws(&s[i]);
		if ((end > -1)
			|| ((end = findchr(&s[i], '\0')) > -1))
		{
			arr[y] = ft_strsub(s, i, end);
			y++;
			i += end;
		}
	}
	return (ft_strsplit_end(arr, y));
}

/*
#include "libft.h"

#include "libft.h"
#include <stdlib.h>

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int	ft_countwords(char const *s)
{
	int word_count;
	int i;

	word_count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (!ft_iswhitespace(s[i]) &&\
		(ft_iswhitespace(s[i + 1]) || s[i + 1] == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

static void	ft_cpychars(char const *s, char *word, int start, int stop)
{
	int i;

	i = 0;
	while (start < stop)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
}

static char	**ft_cpwrds(char **words, char const *s)
{
	int i;
	int j;
	int start;
	int stop;

	i = -1;
	j = 0;
	start = 0;
	stop = 0;
	while (s[i] != '\0')
	{
		if (ft_iswhitespace(s[i]) || s[i] == '\0')
			start = i + 1;
		if (s[i] != '\0' && !ft_iswhitespace(s[i]) && (s[i + 1] == '\0' ||
			ft_iswhitespace(s[i + 1])))
		{
			stop = i + 1;
			words[j] = (char*)ft_memalloc(sizeof(char) * (stop - start + 1));
			ft_cpychars(s, words[j], start, stop);
			j++;
		}
		i++;
	}
	words[j] = 0;
	return (words);
}

char		**ft_strsplit_ws(char const *s)
{
	char	**words;
	int		w_count;

	if (s)
	{
		w_count = ft_countwords(s);
		words = (char**)ft_memalloc(sizeof(char*) * (w_count + 1));
		if (words)
			return (ft_cpwrds(words, s));
	}
	return (0);
}
*/
