/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:39:09 by krioliin          #+#    #+#             */
/*   Updated: 2020/01/17 19:48:04 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

/*
**	@desc	- Checks if argument of argc num is -hexdump and validates value.
**	@param	- t_flags *flags, stores all the flags.
**			- int *param_num, the argument num that is checked.
**	@ret	- 0 if flag is not -hexdump.
**			- -1 if value of the flag is incorrect.
**			- 1 if value is correct.
*/

short	is_hexdump(int argc, char **params, int *param_num, t_flags *flags)
{
	int	i;

	i = 0;
	if (!ft_strcmp((const char *)params[*param_num], "-hexdump"))
	{
		if ((*param_num == argc - 1 || flags->hexdump))
			return (-1);
		else
		{
			*param_num = *param_num + 1;
			while (params[*param_num][i])
			{
				if (!ft_isdigit(params[*param_num][i]))
					return (-1);
				i++;
			}
			flags->hexdump = ft_atoi(params[*param_num]);
			return (1);
		}
	}
	return (0);
}

/*
**	@desc	- Checks if argument of argc num is -dump and validates its value.
**	@param	- t_flags *flags, stores all the flags.
**			- int *param_num, the argument num that is checked.
**	@ret	- 0 if flag is not -dump.
**			- -1 if value of the flag is incorrect.
**			- 1 if value is correct.
*/

short	is_dump(int argc, char **params, int *param_num, t_flags *flags)
{
	int	i;

	i = 0;
	if (!ft_strcmp((const char *)params[*param_num], "-dump"))
	{
		if ((*param_num == argc - 1 || flags->dump))
			return (-1);
		else
		{
			*param_num = *param_num + 1;
			while (params[*param_num][i])
			{
				if (!ft_isdigit(params[*param_num][i]))
					return (-1);
				i++;
			}
			flags->dump = ft_atoi(params[*param_num]);
			return (1);
		}
	}
	return (0);
}

/*
**	@desc	- Adds a new order edit at the end of the array.
**	@param	- t_flags *flags, stores all the flags.
*/

void	add_n_flag(t_flags *flags, int from, int n)
{
	short		index;

	index = 0;
	while (index < MAX_PLAYERS)
	{
		if (flags->players_order[index] == from)
		{
			flags->players_order[index] = n;
			break ;
		}
		index++;
	}
}

/*
**	@desc	- Checks if the order of the players is correct.
**	@param	- short *players_order, an array with order edited by -n flag.
**	@ret	- 0 if players_order already exists.
**			- 1 if players order has to be edited.
*/

short	check_n_pos(int n, short *players_order)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (n == players_order[i])
			return (0);
		i++;
	}
	return (1);
}

/*
**	@desc	- Checks if argument of argc num is -n and validates its value.
**	@param	- Same as is_dump().
**	@ret	- 0 if the flag is not -n.
**			- 1 if the flag is valid.
**			- -1 if the value is incorrect.
*/

short	is_flag_n(int argc, char **params, int *num, t_flags *flags)
{
	int			n;
	static bool	prev_was_nflag;

	if (!ft_strcmp((const char *)params[*num], "-n"))
	{
		if (*num == argc - 2)
			return (-1);
		*num = *num + 1;
		if (!params[*num])
			return (-1);
		n = ft_atoi(params[*num]);
		if (n < 1 || MAX_PLAYERS < n || !check_champion(params[*num + 1]))
			return (-1);
		if (!check_n_pos(n, flags->players_order))
			return (-1);
		if (prev_was_nflag == false)
			prev_was_nflag = true;
		add_n_flag(flags, 0, n);
		return (1);
	}
	if (!prev_was_nflag)
		add_n_flag(flags, 0, -1);
	prev_was_nflag = false;
	return (0);
}

/*
**	@desc	- Checks if argument of argc num is -dump and validates its value.
**	@param	- t_flags *flags, stores all the flags.
**			- int argc, the argument num that is checked.
**	@ret	- 0 if the flag passed is not accepted.
**			- 1 if the flag is valid.
**			- -1 if the value is incorrect. (from is_hexdump(), is_dump()).
*/

short	check_flag(int argc, char **params, int *num, t_flags *flags)
{
	short		return_val;

	if ((return_val = is_hexdump(argc, params, num, flags)))
		return (return_val);
	else if ((return_val = is_dump(argc, params, num, flags)))
		return (return_val);
	else if (!ft_strcmp(params[*num], "-v"))
	{
		flags->v = true;
		return (1);
	}
	return_val = is_flag_n(argc, params, num, flags);
	return (return_val);
}
