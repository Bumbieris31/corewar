/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_arena.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:25:13 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 19:41:50 by asulliva      ########   odam.nl         */
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
# define NB_PLAYERS vm->nb_players
# define CHAMPS vm->champs
# define ARENA vm->arena
# define GAME vm->game
# define CURSORS GAME->cursors
# define FLAG vm->flag

typedef struct s_vm t_vm;
typedef struct s_flags t_flags;
typedef struct s_args t_args;
typedef struct s_champ t_champ;
typedef struct s_cursor t_cursor;
typedef struct s_game t_game;


/*
**	@desc	- struct that holds cursors in a linked list
**	@param	- long id,
**			- int moved, 1 or 0, to know if it moved recently
**			- int carry, 1 or 0, carry for ZJMP
**			- int opcode, current operationcode 
**			- int last_live, last live call of cursor
**			- int wait_cycles, total amont of waitcycles for this operation
**			- int pos, current position of the cursor
**			- int pc, amount of bytes needed to jump to next operation
**			- int reg[REG_NUMBER], registries for this cursor
**			- t_cursor *next, next cursor (if any)
*/

struct			s_cursor
{
	long		id;
	int			moved;
	int			carry;
	int			opcode;
	int			last_live;
	int			wait_cycles;
	int			pos;
	int			pc;
	int			reg[REG_NUMBER];
	t_cursor	*next;
	/* For visualisation */
	int			prev_xy[2];
	int			prev_val;
};

/*
**	@desc	- struct holds info for all champs
**	@param	- int id, unique id of player
**			- int size, size of the exec code
**			- char *name, name of the champ
**			- char *comment, comment of the champ
**			- int lives, amount of live calls
**			- int last_live, last live call (nb_cycle)
**			- int start_pos, starting position of player
**			- int code, exec code of the player
*/

struct		s_champ
{
	int		id;
	int		size;
	char	*name;
	char	*comment;
	int		lives;
	int		last_live;
	int		start_pos;
	t_byte	*code;
};

/*
**	@desc	- struct for the option flags
**	@param	- int dump, sets the cycles for the dump flag
**			- int v, 1 or 0 for visualizer
**			- short player_order[MAX_PLAYERS], stores the player order for
**			the -n flag
*/

struct		s_flags
{
	int		dump;
	int		v;
	short	play_order[MAX_PLAYERS];
};

/*
**	@desc	- struct for the arguments of operations
**	@param	- int value, stores value of the argument
**			- int size, stores size of the argument
**			- int type, flag for type of argument
*/

struct		s_args
{
	int		value;
	int		size;
	int		type;
};

/*
**	@desc	- struct that holds all data of the game
**	@param	- int winner, id of the winner
**			- int cycles, current nb of cycles
**			- int lives, amount of live calls
**			- int processes, amount of processes running
**			- int cycles_to_die, cycles till next check
**			- int last_live, last live call
**			- int nb_ctd, nb of cycle to die checks performed
**			- t_cursor *cursors, linked list of cursors in the game
*/

struct			s_game
{
	int			winner;
	int			cycles;
	int			lives;
	int			processes;
	int			cycles_to_die;
	int			last_live;
	int			nb_ctd;
	t_cursor	*cursors;
};

/*
**	@desc	- main struct of the VM
**	@param	- short nb_players, total number of players
**			- t_byte arena[MEM_SIZE], arena the game takes place,
**			MEM_SIZE is define
**			- t_flags *flag, struct stores the flags
**			- t_champs *champ, champions
*/

struct		s_vm
{
	short	nb_players;
	t_byte	arena[MEM_SIZE];
	t_flags	*flag;
	t_champ	*champs;
	t_game	*game;
};

typedef enum				e_argctype
{
	REG = 1,
	DIR,
	IND
}							e_argctype;

/*
********************************* UTILS *********************************
*/
void	error(char *message, char *file);
int		swap_32(int nb);
int		arg_size(int type, int opcode);
void	decode(int octal, e_argctype args[3]);
int		get_pc(int opcode, int octal);
int		dump64(t_vm *vm);
int		wait_cycle(int opcode);

/*
***************************** PARSING ARGS ******************************
*/
void	parse_args(int ac, char **av, t_flags *flags);
int		check_flag(int ac, char **av, int *i, t_flags *flags);
int 	is_flag_n(int argc, char **params, int *num, t_flags *flags);
int		check_champion(char *file_name);
int		champ_name(char *name);
int		get_amount(int nb_init);
char	**save_players(char *name);
void	parse_champs(t_vm *vm);
int		null_byte(const int fd);
int		champ_code_size(t_champ *champ, const int fd);
int		get_champ_code(t_champ *champ, const int fd);
void	set_champ(t_champ *champ, short player_order[MAX_PLAYERS],\
		int num, int nb_players);
int		get_bytes(t_byte *arena, int idx, int amount);
int		get_index(int current, int move);

/*
********************************* INIT **********************************
*/
void	init_game(t_vm *vm);
void	init_cursors(t_vm *vm);

/*
********************************* GAME **********************************
*/
void	start_game(t_vm *vm);
void	execute(t_vm *vm);
void	mv_cursor(t_vm *vm, t_cursor *c, int move);
t_args  *get_args(t_cursor *c, t_byte octal, t_byte *arena);
#endif