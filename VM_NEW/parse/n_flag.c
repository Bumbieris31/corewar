/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   n_flag.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 20:18:40 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 15:55:53 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function adds -n flag to player order
**	@param	- t_flags *flags, initialized flag struct
**			- int from, allways 0?
**			- int n, new position of player
*/

static void	add_n_flag(t_flags *flags, int from, int n)
{
	short		index;

	index = 0;
	while (index < MAX_PLAYERS)
	{
		if (flags->play_order[index] == from)
		{
			flags->play_order[index] = n;
			break ;
		}
		index++;
	}
}

/*
**	@desc	- function checks if value for -n flag is in range
**	@param	- int n, value behind -n flag
**			- short *play_order, order of players
**	@return	- 1 on succes, 0 on failure
*/

static int	check_n_pos(int n, short *play_order)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (n == play_order[i])
			return (0);
		i++;
	}
	return (1);
}

/*
**	@desc	- function for the -n flag
**	@param	- int ac, nb of arguments
**			- char **av, arguments
**			- int *i, index of current arg
**			- t_flags *flags, initialized flag struct
**	@return	- 1 if flag, 0 if not flag
*/

int			is_flag_n(int ac, char **av, int *i, t_flags *flags)
{
	int			n;
	static int	prev_was_nflag;

	if (!ft_strcmp((const char *)av[*i], "-n"))
	{
		if (*i == ac - 2)
			error("-n flag needs numeric value", NULL);
		*i = *i + 1;
		if (!av[*i])
			error("-n flag needs numeric value", NULL);
		n = ft_atoi(av[*i]);
		if (n < 1 || MAX_PLAYERS < n || !check_champion(av[*i + 1]))
			error("Invalid value for -n flag", NULL);
		if (!check_n_pos(n, flags->play_order))
			error("Invalid value for -n flag", NULL);
		if (!prev_was_nflag)
			prev_was_nflag = 1;
		add_n_flag(flags, 0, n);
		return (1);
	}
	if (!prev_was_nflag)
		add_n_flag(flags, 0, -1);
	prev_was_nflag = 0;
	return (0);
}
