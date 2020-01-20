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

NAME =		corewar

SRC =		main.c

LIBFT = 	./libft

VM =		./vm

LIBFTA =	./libft/libft.a

VMA =		./vm/libvm.a

FTPRINTFA =	./ft_printf/libftprintf.a

OBJ =		$(SRC:.c=.o)

.PHONY: 	all clean fclean re

all:		$(NAME)

%.o:		%.c
			gcc -Wall -Werror -Wextra -g -I $(LIBFT) -I $(VM) -o $@ -c $<

$(NAME):	$(LIBFTA) $(VMA) $(FTPRINTFA) $(OBJ) ./libft/libft.a ./vm/libvm.a ./ft_printf/libftprintf.a
			gcc -Wall -Werror -Wextra -g -o corewar $(OBJ) -L ./libft -lft -L ./vm -lvm -L ./ft_printf -lftprintf -lncurses

FORCE:		;

$(VMA):		FORCE
			make -C ./vm

$(FTPRINTFA):		FORCE
			make -C ./ft_printf

$(LIBFTA):	FORCE
			make -C ./libft

clean:
			rm -f main.o
			make clean -C ./ft_printf
			make clean -C ./vm
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./ft_printf
			make fclean -C ./libft
			make fclean -C ./vm

re:			fclean all
