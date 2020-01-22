# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/21 19:23:26 by asulliva       #+#    #+#                 #
#    Updated: 2020/01/22 15:21:25 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror -g -lncurses
LIB			= ft_printf/libftprintf.a
HEADER		= -I./ft_printf/includes -I includes/
NAME		= corewar

SRC			= main.c\
			parse/parse_args.c parse/flag.c parse/n_flag.c\
			parse/check_champs.c parse/parse_champs.c parse/champ_utils.c\
			parse/set_champ.c\
			utils/error.c utils/op.c utils/swap32.c utils/arg_size.c\
			utils/decode.c utils/get_pc.c

all: $(NAME)

$(NAME):
	@gcc  $(FLAGS) -o $(NAME) $(SRC) $(HEADER) $(LIB)
	@echo "\033[0;32mVM successfully created\033[0m"

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf *.dSYM

re: fclean $(NAME)
