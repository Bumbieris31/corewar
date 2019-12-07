/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   name_comment.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 13:04:41 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/07 14:00:46 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**  @desc   - function counts the quotes on the line with .name and .comment
**  @param  - char *s, the .name or .comment string (one line) 
**  @return - return 2 if 2 quotes in line
**          - return 1 if 1 quote in line
**          - return 0 if no quotes AKA and error
*/

static int  count_quotes(char *s)
{
    int i;
    int quotes;

    i = 0;
    quotes = 0;
    while (s[i])
    {
        if (s[i] == '"')
            quotes++;
        i++;
    }
    if (quotes > 1)
        return (2);
    else if (quotes > 0)
        return (1);
    else
        return (0);
}

/*
**  @desc   - function gets .name and .comment if it is multiple lines
**  @param  - t_asm *data, main struct
**          - char **s, pointer to line read from the line and to start at
**          - int type, 0 if name, 1 if comment
*/

static void multi_line(t_asm *data, char **s, int type)
{
    char    *line;
    char    *check;
    char    *temp;

    type = 0;
    while (get_next_line(data->rfd, &line))
    {
        check = ft_strchr(line, '"');
        if (check)
            check = NULL;
        if (ft_strstr(line, NAME_CMD_STRING) || ft_strstr(line, COMMENT_CMD_STRING))
            error("No closing quote");
        temp = ft_strjoin(*s, line);
        free_arr(&line, NULL, 0);
        *s = temp;
        temp = NULL;
        if (ft_strchr(*s, '"'))
            break ;
        *s = ft_strjoinone(*s, '\n');
    }
    ft_printf("[%s]\n", *s);
}

/*
**	@desc	- function parses the .name and .comment commands
**	@param	- t_asm *data, main struct
**			- char *s, line read from the file
**          - int type, 0 if name, 1 if comment
*/

void		parse_nc(t_asm *data, char *s, int type)
{
	char	**split;
    int     quotes;

	split = ft_strsplit(s, '"');
    quotes = count_quotes(s);
    if (!quotes)
        error("Incorrect string in .name/.comment");
    if (split[1])
        s = ft_strdup(split[1]);
    else if (!split[1])
        s = ft_strdup("");
    if (quotes == 1)
    {
        s = ft_strjoinone(s, '\n');
        multi_line(data, &s, type);
    }
    free_arr(NULL, &split, 1);
	data->wfd = 0;
}
