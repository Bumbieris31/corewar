# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/06 15:28:37 by asulliva       #+#    #+#                 #
#    Updated: 2020/02/06 16:58:07 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= asm
SRCS	= main \
			utils/error utils/instruction utils/label_util utils/get_value\
			utils/rm_comma\
			parse/parse parse/get_line parse/name_comment parse/label\
			parse/parse_op parse/get_label\
			free/free_arr
HEADER	= includes/asm.h
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g
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
