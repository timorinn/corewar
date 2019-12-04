# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 17:55:08 by bford             #+#    #+#              #
#    Updated: 2019/12/04 20:16:27 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		ft_valid_input.c	\
			ft_init_input.c		\
			ft_init_player.c	\
			ft_lstnew_player.c	\
			ft_lstdel_player.c

OBJ =		$(SRC:.c=.o)

HEAD =		vm.h

NAME =		libvm.a

all:		$(NAME)

$(NAME):	$(OBJ)
			ar -rcs $(NAME) $(OBJ)

%.o:		%.c $(HEAD)
			gcc -I ./ -Wall -Wextra -Werror -g -c $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
