# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 17:55:08 by bford             #+#    #+#              #
#    Updated: 2019/12/23 21:00:34 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		ft_valid_input.c		\
			ft_init_input.c			\
			ft_init_player.c		\
			ft_lstnew_player.c		\
			ft_lstlen_player.c		\
			ft_lstdel_player.c		\
			ft_error.c				\
			ft_map.c				\
			ft_print_map.c			\
			ft_print_players.c		\
			ft_print_map_single.c	\
			ft_make_array_careta.c	\
			ft_print_careta.c		\
			\
			ft_do_cycle.c			\
			ft_init_t_dir.c			\
			ft_init_t_ind.c			\
			ft_init_args.c			\
			ft_dir_or_ind.c			\
			ft_move.c				\
			vm_validate_args.c		\
			\
			ft_ld.c					\
			ft_lld.c				\
			ft_zjmp.c				\
			ft_st.c					\
			ft_fork.c				\
			ft_lfork.c

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
