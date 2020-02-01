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
VM_PATH =		./src/vm_src
ASM_PATH =		./src/asm_src
ASM_BINARY =	asm

LIBFT_PATH = ./libft/
FT_PRINTF_PATH = ./ft_printf/

all:		$(NAME) $(ASM_BINARY)

$(NAME): FORCE $(ASM_BINARY)
		make -C $(VM_PATH)

$(ASM_BINARY): FORCE
			make -C $(ASM_PATH)

clean:
			make clean -C $(VM_PATH)
			make clean -C $(ASM_PATH)
			make clean -C $(LIBFT_PATH)
			make clean -C $(FT_PRINTF_PATH)

fclean:
			make fclean -C $(VM_PATH)
			make fclean -C $(ASM_PATH)
			make fclean -C $(LIBFT_PATH)
			make fclean -C $(FT_PRINTF_PATH)

re:			fclean all

FORCE: ;
