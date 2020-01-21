/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_arena.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:25:13 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/21 21:01:11 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_ARENA_H
# define VM_ARENA_H

# include <ncurses.h>
# include <fcntl.h>
# include <stdlib.h>
# include "op.h"
# include "../ft_printf/includes/ft_printf.h"
# include "operations.h"
// # include "corewar_visual.h"

# define OP_NBR 16
# define DEBUG_MOD 0

typedef struct s_vm t_vm;
typedef struct s_flags t_flags;
typedef struct s_args t_args;

struct	s_flags
{
	int		dump;
	int		v;
	short	play_order[MAX_PLAYERS];
};

struct s_args
{
	int		value;
	int		size;
	int		type;
};

struct  s_vm
{
	short	nb_players;
	t_byte	arena[MEM_SIZE];
	t_flags	*flag;
};

void	error(char *message);
void	parse_args(int ac, char **av, t_flags *flags);
int		check_flag(int ac, char **av, int *i, t_flags *flags);
int 	is_flag_n(int argc, char **params, int *num, t_flags *flags);
int		check_champion(char *file_name);
int		champ_name(char *name);
#endif