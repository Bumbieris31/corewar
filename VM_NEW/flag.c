/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:54:25 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/21 21:34:49 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

/*
**	@desc	- function checks for dump flag
**	@param	- int ac, nb of arguments
**			- char **av, arguments
**			- int *param_num, current arg index
**			- t_flags *flags, initialized flag struct
**	@return	- 1 if flag, 0 if not
*/

static int	is_dump(int ac, char **av, int *param_num, t_flags *flags)
{
	int	i;

	i = 0;
	if (!ft_strcmp((const char *)av[*param_num], "-dump"))
	{
		if ((*param_num == ac - 1 || flags->dump))
			error("Dump flag needs numeric value");
		else
		{
			*param_num = *param_num + 1;
			while (av[*param_num][i])
			{
				if (!ft_isdigit(av[*param_num][i]))
					error("Dump flag needs numeric value");
				i++;
			}
			flags->dump = ft_atoi(av[*param_num]);
			return (1);
		}
	}
	return (0);
}

/*
**	@desc	- function checks for visual flag
**	@param	- char **av, arguments
**			- int *i, current arg index
**			- t_flags *flags, initialized flag struct
**	@return	- 1 if flag, 0 if not
*/

static int	is_visual(char **av, int *i, t_flags *flags)
{
	if (!ft_strcmp(av[*i], "-v"))
	{
		flags->v = 1;
		return (1);
	}
	return (0);
}

/*
**	@desc	- main flag checking function
**	@param	- int ac, nb of arguments
**			- char **av, arguments
**			- int *i, index of arg we are at
**			- t_flags *flags, initialized flag struct
**	@return	- 0 if no flags, !0 if flags
*/

int			check_flag(int ac, char **av, int *i, t_flags *flags)
{
	int	ret;

	ret = is_dump(ac, av, i, flags);
	if (ret)
		return (ret);
	ret = is_visual(av, i, flags);
	if (ret)
		return (ret);
	ret = is_flag_n(ac, av, i, flags);
	return (ret);	
}