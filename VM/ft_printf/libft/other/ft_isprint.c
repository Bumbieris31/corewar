/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:12 by krioliin       #+#    #+#                */
/*   Updated: 2019/03/23 19:59:26 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	return (32 <= c && c < 127);
}
