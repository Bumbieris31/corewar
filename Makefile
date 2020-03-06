# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/29 17:45:05 by krioliin       #+#    #+#                 #
#    Updated: 2020/03/06 20:29:07 by abumbier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ASM		:=	asm
PATH_VM	:=	vm/
PATH_ASM:=	asm_/
PATH_DSM:=	dsm_/
PRINTF	:=	VM/ft_printf/
LIB		:=	LIBFT_SRCS/

all:
	@make -C $(LIB)
	@make -C $(PRINTF)
	@make -C $(PATH_ASM)
	@make -C $(PATH_VM)
	@make -C $(PATH_DSM)
	@mv $(PATH_ASM)asm .
	@mv $(PATH_VM)corewar .
	@mv $(PATH_DSM)dsm .
	@chmod 744 asm
	@chmod 744 corewar
	@chmod 744 dsm

mre:
	@make mre -C $(PATH_ASM)
	@make mre -C $(PATH_VM)
	@make mre -C $(PATH_DSM)
	@ln -fs $(PATH_ASM)dsm dsm
	@ln -fs $(PATH_ASM)asm asm
	@ln -fs $(PATH_VM)corewar corewar
	@chmod 744 asm corewar

clean:
	@make -C $(LIB) clean
	@make -C $(PRINTF) clean
	@make -C $(PATH_ASM) clean
	@make -C $(PATH_VM) clean
	@make -C $(PATH_DSM) clean

fclean: clean
	@rm -f asm $(LIB)libft.a
	@rm -f asm $(PRINTF)libftprintf.a
	@rm -f asm $(PATH_ASM)asm
	@rm -f corewar $(PATH_VM)corewar
	@rm -f dsm $(PATH_DSM)dsm

re: fclean all