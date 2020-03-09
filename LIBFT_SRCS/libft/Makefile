NAME = libft.a

SRC 	= ft_memset.c \
		ft_memmove.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_strlen.c \
		ft_memdel.c \
		ft_strsplit.c \
		ft_bzero.c \
		ft_memalloc.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_strchr.c \
		ft_strstr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_striter.c \
		ft_striteri.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_strclr.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_count_words.c \
		ft_str_toupper.c \
		ft_str_tolower.c \
		ft_putwchar.c \
		ft_putwstr.c \
		ft_print_int_array.c \
		get_next_line.c \
		ft_list_add_back.c \
		ft_strjoinone.c \
		ft_str_is_digit.c \
		ft_lstrev.c \
		ft_strndup.c \
		ft_strsplit_ws.c \
		ft_wordlen.c
FLAGS	= -Wall -Werror -Wextra
CC		= gcc
OBJS	:= $(SRC:%.c=%.o)

HEADER 	= ./libft.h

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "\033[0;32mlibft.a successfully created\033[0m"
	@ranlib $(NAME)

$(OBJS):
	@gcc $(FLAGS) -c $(SRC) -I $(HEADER)
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
