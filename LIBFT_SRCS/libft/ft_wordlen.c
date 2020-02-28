/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wordlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 15:47:30 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/19 16:00:37 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordlen(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}
