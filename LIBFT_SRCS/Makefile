# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/25 13:40:40 by asulliva       #+#    #+#                 #
#    Updated: 2020/07/23 18:00:46 by abumbier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc
LIBFT		= libft/*.c
INCLUDES	= ft_printf.h
SRCS 		= precision.c width.c extra.c modifier.c \
conversion.c go_print.c \
handle_d.c handle_c.c ft_printf.c handle_s.c \
handle_modulo.c handle_p.c \
handle_f.c make_fstr.c handle_u.c handle_sx.c \
handle_o.c defines.c \
handle_f1.c handle_o1.c handle_p1.c handle_s1.c \
handle_d1.c handle_d2.c handle_d3.c

OBJS		:= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@$(CC) -c $(SRCS) $(LIBFT) -I$(INCLUDES)
	@echo "\033[0;32mft_printf and libft successfully created\033[0m"
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS) *.o
	@echo "\033[0;33mClean ft_printf and libft\033[0m"
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
