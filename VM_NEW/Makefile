# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/21 19:23:26 by asulliva       #+#    #+#                 #
#    Updated: 2020/01/21 21:48:54 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror -g -lncurses
LIB			= ft_printf/libftprintf.a
HEADER		= -I./ft_printf/includes -I includes/
NAME		= corewar

SRC			= main.c parse_args.c flag.c n_flag.c champs.c\
			utils/error.c utils/op.c

all: $(NAME)

$(NAME):
	@clang  $(FLAGS) -o $(NAME) \
	$(SRC) $(HEADER) $(LIB)
	@echo "\033[0;32mVM successfully created\033[0m"

clean:
	@rm -f *.o
	@rm -rf *.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
