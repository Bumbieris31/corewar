/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_line.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 15:53:41 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/06 15:55:02 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	@desc	- function trims a string split on comment_char
**	@param	- char **split, the split string to trim
**			- char *tmp, pointer to be freed
*/

static char	*set_trimmed(char **split, char *tmp)
{
	char	*line;
	char	*s;

	line = ft_strdup(split[0]);
	s = ft_strtrim(line);
	free(line);
	free_arr(&tmp, &split, 2);
	return (s);
}

/*
**	@desc	- function gets line out of file trims it from whitespace,
**			- checks for comment tags copies relevant data to pointer
**	@param	- int fd, file descriptor of the opened file
**			- char **s, pointer to string to write file content in
**	@return	- int ret, amount of bytes read out of the file
*/

int			get_line(t_asm *data, int fd, char **s, char **split)
{
	int		ret;
	char	*line;
	char	*tmp;

	ret = get_next_line(fd, &line);
	data->lines++;
	tmp = ft_strtrim(line);
	free(line);
	if (!tmp || !ft_strlen(tmp) ||
	tmp[0] == COMMENT_CHAR || tmp[0] == ALT_COMMENT_CHAR)
	{
		*s = ft_strnew(0);
		free(tmp);
		return (ret);
	}
	*s = tmp;
	if (ft_strchr(tmp, COMMENT_CHAR))
		split = ft_strsplit(tmp, COMMENT_CHAR);
	else if (ft_strchr(tmp, ALT_COMMENT_CHAR))
		split = ft_strsplit(tmp, ALT_COMMENT_CHAR);
	if (split)
		*s = set_trimmed(split, tmp);
	return (ret);
}
