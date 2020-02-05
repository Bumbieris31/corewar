# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abumbier <abumbier@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/05 14:20:22 by asulliva       #+#    #+#                 #
#    Updated: 2020/02/05 16:48:49 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= asm
SRCS	= main error parse free name_comment label instruction check_syntax \
valid_oper_line label_util token create_cor swap_endian \
write_cor_file encoding_byte write_size write_champ_byte write_dir
HEADER	= includes/asm.h
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g
HEADER	= includes/dsm.h
LIB		= ../ft_printf/libftprintf.a
OBJS	:= $(SRCS:%=%.o)
SRCS	:= $(SRCS:%=%.c)

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $^ -o $(NAME) $(LIB)
	@echo "\033[0;32m[ + ] $(NAME) has been compiled\033[0m"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $< -I $(LIB)

clean:
	@rm -f $(OBJS)
	@echo "\033[0;33m[ - ] removed asm files\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
