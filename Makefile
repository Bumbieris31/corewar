# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/29 17:45:05 by krioliin       #+#    #+#                 #
<<<<<<< HEAD
#    Updated: 2020/01/30 15:19:18 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# @ ln -fs $(PATH_VM)corewar corewar
# @ ln -fs $(PATH_DSM)dsm dsm
=======
#    Updated: 2020/02/23 14:30:25 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

>>>>>>> aidan
ASM		:=	asm
PATH_VM	:=	vm/
PATH_ASM:=	asm_/
PATH_DSM:=	dsm_/
<<<<<<< HEAD
LIB		:=	ft_printf/
=======
LIB		:=	VM/ft_printf/
>>>>>>> aidan

all:
	@make -C $(LIB)
	@make -C $(PATH_ASM)
	@make -C $(PATH_VM)
	@make -C $(PATH_DSM)
<<<<<<< HEAD
	@ mv $(PATH_ASM)asm .
	@ mv $(PATH_VM)corewar .
	@ mv $(PATH_DSM)dsm .
=======
	@mv $(PATH_ASM)asm .
	@mv $(PATH_VM)corewar .
	@mv $(PATH_DSM)dsm .
>>>>>>> aidan
	@chmod 744 asm
	@chmod 744 corewar
	@chmod 744 dsm

mre:
<<<<<<< HEAD
	@ make mre -C $(PATH_ASM)
	@ make mre -C $(PATH_VM)
	@ make mre -C $(PATH_DSM)
	@ ln -fs $(PATH_ASM)dsm dsm
	@ ln -fs $(PATH_ASM)asm asm
	@ ln -fs $(PATH_VM)corewar corewar
	@ chmod 744 asm corewar
=======
	@make mre -C $(PATH_ASM)
	@make mre -C $(PATH_VM)
	@make mre -C $(PATH_DSM)
	@ln -fs $(PATH_ASM)dsm dsm
	@ln -fs $(PATH_ASM)asm asm
	@ln -fs $(PATH_VM)corewar corewar
	@chmod 744 asm corewar
>>>>>>> aidan

clean:
	@make -C $(LIB) clean
	@make -C $(PATH_ASM) clean
	@make -C $(PATH_VM) clean
	@make -C $(PATH_DSM) clean

fclean: clean
	@rm -f asm $(LIB)libftprintf.a
	@rm -f asm $(PATH_ASM)asm
	@rm -f corewar $(PATH_VM)corewar
	@rm -f dsm $(PATH_DSM)dsm

<<<<<<< HEAD
re: fclean all

=======
re: fclean all
>>>>>>> aidan
