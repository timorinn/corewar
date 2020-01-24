# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 13:37:52 by bford             #+#    #+#              #
#    Updated: 2020/01/20 18:21:36 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: 	all clean fclean re

NAME =		corewar

VM_BINARY =		corewar
VM_PATH =		./vm_src
ASM_PATH =		./asm_src
ASM_BINARY =	asm


all:		$(NAME) $(VM_BINARY) $(ASM_BINARY)

$(NAME): $(VM_BINARY) $(ASM_BINARY)

$(VM_BINARY):
			make -C $(VM_PATH)

$(ASM_BINARY):
			make -C $(ASM_PATH)

clean:
			make clean -C $(VM_PATH)
			make clean -C $(ASM_PATH)

fclean:
			make fclean -C $(VM_PATH)
			make fclean -C $(ASM_PATH)

re:			fclean all
