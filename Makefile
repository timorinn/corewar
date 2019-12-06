# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 13:37:52 by bford             #+#    #+#              #
#    Updated: 2019/12/06 18:45:16 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		corewar

SRC =		main.c

LIBFT = 	./libft

VM =		./vm

LIBFTA =	./libft/libft.a

VMA =		./vm/libvm.a

OBJ = $(SRC:.c=.o)

.PHONY: 	all clean fclean re

all:		$(NAME)

%.o:		%.c
			gcc -Wall -Werror -Wextra -I $(LIBFT) -I $(VM) -o $@ -c $<

$(NAME):	$(LIBFTA) $(VMA) $(OBJ) ./libft/libft.a ./vm/libvm.a
			gcc -Wall -Werror -Wextra -g -o corewar $(OBJ) -L ./libft -lft -L ./vm -lvm -lncurses

FORCE:		;

$(VMA):		FORCE
			make -C ./vm

$(LIBFTA):	FORCE
			make -C ./libft

clean:
			rm -f main.o
			make clean -C ./libft
			make clean -C ./vm

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft
			make fclean -C ./vm

re:			fclean all
