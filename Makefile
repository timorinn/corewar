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

LIBFT_PATH =	./libft/
LIBFT_A =	libft.a
LIBFT = $(addprefix $(LIBFT_PATH),$(LIBFT_A))

FT_PRINTF_PATH = ../ft_printf/
FT_PRINTF_A = libftprintf.a
FT_PRINTF = $(addprefix $(FT_PRINTF_PATH),$(FT_PRINTF_A))

VM =		./vm
ASM =		./asm


all:		$(NAME)

$(NAME): $(VM) $(ASM)

$(VM): $(LIBFT) $(FT_PRINTF)
			make -C ./vm

$(ASM): $(LIBFT) $(FT_PRINTF)
			make -C ./asm

$(FTPRINTFA):
			make -C ./ft_printf

$(LIBFTA):
			make -C ./libft

clean:
			make clean -C ./ft_printf
			make clean -C ./vm
			make clean -C ./libft

fclean:
			make fclean -C ./ft_printf
			make fclean -C ./libft
			make fclean -C ./vm

re:			fclean all
