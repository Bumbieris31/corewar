# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abumbier <abumbier@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/05 14:20:22 by asulliva       #+#    #+#                 #
#    Updated: 2020/02/25 20:58:35 by abumbier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= asm
SRCS	= main error parse free name_comment label instruction check_syntax \
		valid_oper_line label_util token create_cor swap_endian \
		write_cor_file encoding_byte write_size write_champ_byte write_dir \
		find_label check_instruction get_next_label

CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g
HEADER	= includes/asm.h
LIBFTH	= ../LIBFT_SRCS/libft/
LIB		= ../LIBFT_SRCS/libft.a
OBJS	:= $(SRCS:%=%.o)
SRCS	:= $(SRCS:%=%.c)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ../LIBFT_SRCS/
	@$(CC) $(FLAGS) $^ -o $(NAME) $(LIB)
	@echo "\033[0;32m[ + ] $(NAME) has been compiled\033[0m"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $< -I $(LIBFTH)

clean:
	@rm -f $(OBJS)
	@echo "\033[0;31m[ - ] removed object files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m[ - ] removed $(NAME)\033[0m"

re: fclean all
