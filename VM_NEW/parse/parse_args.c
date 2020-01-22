/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:34:02 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 12:55:47 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function sets and returns static var nb_players
**	@param	- int nb_init, to give nb_players value != 0
**	@return	- int nb_players, amount of players
*/

int			get_amount(int nb_init)
{
	static int	nb_players;

	if (!nb_players)
	{
		nb_players = nb_init;
		return (0);
	}
	return (nb_players);
}

/*
**	@desc	- function checks the order of players
**	@param	- short order[MAX_PLAYERS], array with order of players
**			- int nb_players, number of players
**	@return	- 1 on success, 0 on error
*/

static int	check_order(short order[MAX_PLAYERS], int nb_players)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (nb_players < order[i])
			return (0);
		i++;
	}
	get_amount(nb_players);
	return (1);
}

/*
**	@desc	- function checks if argument is flag or champ
**	@param	- int ac, nb of arguments
**			- char **av, arguments
**			- int *i, index of arg we are at
**			- t_flags *flags, initialized flag struct
**	@return	- 1 on success, 0 on error
*/

static int	check_arg(int ac, char **av, int *i, t_flags *flags)
{
	short			flag;
	static short	nb_players;

	flag = check_flag(ac, av, i, flags);
	if (flag)
	{
		if (ac - 1 == *i && !check_order(flags->play_order, nb_players))
			return (0);
		return (flag);
	}
	if (champ_name(av[*i]))
	{
		nb_players++;
		if ((ac - 1 == *i && !check_order(flags->play_order, nb_players))
		|| MAX_PLAYERS < nb_players)
			return (0);
	}
	else
		return (0);
	return (1);	
}

/*
**	@desc	- main controller function for parsing arguments
**	@param	- int ac, nb of arguments
**			- char **av, arguments
**			- t_flags *flags, initialized flag struct
*/

void	parse_args(int ac, char **av, t_flags *flags)
{
	int		i;

	i = 1;
	flags->dump = 0;
	if (ac < 2)
		error("usage", NULL);
	while (i < ac)
	{
		if (!check_arg(ac, av, &i, flags))
			error("Invalid argument", NULL);
		i++;
	}
}
