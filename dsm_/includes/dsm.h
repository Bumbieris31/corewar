/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dsm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 20:09:35 by asulliva       #+#    #+#                */
<<<<<<< HEAD:dsm_/includes/dsm.h
/*   Updated: 2020/01/30 16:26:15 by asulliva      ########   odam.nl         */
=======
/*   Updated: 2020/02/23 14:33:11 by asulliva      ########   odam.nl         */
>>>>>>> aidan:dsm_/includes/dsm.h
/*                                                                            */
/* ************************************************************************** */

#ifndef __DSM_H
# define __DSM_H
# define MAX_INT 2147483647

# include <fcntl.h>
# include <unistd.h>
<<<<<<< HEAD:dsm_/includes/dsm.h
# include "../../ft_printf/includes/ft_printf.h"
=======
# include "../../LIBFT_SRCS/libft/libft.h"
>>>>>>> aidan:dsm_/includes/dsm.h
# include "../../VM/includes/op.h"

# define LIVE		0x01
# define LD			0x02
# define ST			0x03
# define ADD		0x04
# define SUB		0x05
# define AND		0x06
# define OR			0x07
# define XOR		0x08
# define LLD		0x0d
# define AFF		0x10
# define ZJMP		0x09
# define LDI		0x0a
# define STI		0x0b
# define FORK		0x0c
# define LLDI		0x0e
# define LFORK		0x0f
# define NB_OPS		0x0f
# define REG		-1
# define DIR		-2
# define IND		-3

typedef struct s_dsm	t_dsm;
<<<<<<< HEAD:dsm_/includes/dsm.h
typedef struct s_oop	t_oop;
=======
typedef struct s_oper	t_oper;
>>>>>>> aidan:dsm_/includes/dsm.h

struct		s_dsm
{
	int		rfd;
	int		wfd;
	int		size;
	char	*name;
	char	*comment;
	char	*file_name;
<<<<<<< HEAD:dsm_/includes/dsm.h
	t_oop	*ops;
};

struct		s_oop
{
	char	*op_name;
	char	**args;
	t_oop	*next;
=======
	t_oper	*ops;
};

struct		s_oper
{
	char	*op_name;
	char	**args;
	t_oper	*next;
>>>>>>> aidan:dsm_/includes/dsm.h
};

/*
**	args.c
*/
<<<<<<< HEAD:dsm_/includes/dsm.h
int			find_args(t_oop *curr, int enc_byte, int arg_amnt, int op);
=======
int			find_args(t_oper *curr, int enc_byte, int arg_amnt, int op);
>>>>>>> aidan:dsm_/includes/dsm.h

/*
**	convert.c
*/
int			convert(unsigned char *s, int size);

/*
**	exec_code.c
*/
void		get_exec_code(t_dsm *data);

/*
**	free.c
*/
void		free_all(t_dsm *data);

/*
**	main.c
*/
int			get_rfd(int rfd);

/*
**	parse.c
*/
void		parse(t_dsm *data);

/*
**	utils.c
*/
int			enc_byte(int op);
int			dir_size(int op);
int			arg_amnt(int op);
void		error(char *message, int usage);
void		free_arr(char **arr1, char ***arr2, int flag);

/*
**	write.c
*/
void		write_file(t_dsm *data);
#endif
