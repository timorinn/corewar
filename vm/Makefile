# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 17:55:08 by bford             #+#    #+#              #
#    Updated: 2020/01/05 16:25:27 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		ft_valid_input.c		\
			ft_init_input.c			\
			ft_init_player.c		\
			ft_lstnew_player.c		\
			ft_lstlen_player.c		\
			ft_lstdel_player.c		\
			ft_error.c				\
			ft_arena.c				\
			ft_print_map.c			\
			ft_print_players.c		\
			ft_print_map_single.c	\
			vm_make_start_list_cursor.c		\
			ft_print_cursor.c		\
			\
			ft_do_cycle.c			\
			ft_init_t_dir.c			\
			ft_init_t_ind.c			\
			ft_init_args.c			\
			vm_init_cycle.c			\
			ft_dir_or_ind.c			\
			ft_move.c				\
			vm_validate_args.c		\
			vm_get_args.c			\
			vm_unfold_indirects.c	\
			ft_rewrite_map.c		\
			\
			vm_op_ld.c				\
			vm_op_ldi.c				\
			vm_op_lldi.c			\
			vm_op_lld.c				\
			vm_op_zjmp.c			\
			vm_op_st.c				\
			op_all_fork.c			\
			vm_op_fork.c			\
			vm_op_lfork.c			\
			vm_op_add.c				\
			vm_op_and.c				\
			vm_op_live.c			\
			vm_op_sub.c				\
			vm_op_sti.c				\
			op_bitwise.c			\
			op_add_sub.c			\
			vm_op_or.c				\
			vm_op_xor.c				\
			vm_op_aff.c				\
			\
			op_all_fork.c			\
			op_bitwise.c			\
			op_load.c				\
			op_load_i.c				\
			\
			vm_check_cursor.c		\
			vm_lstdel_cursor.c

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
