# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 17:55:08 by bford             #+#    #+#              #
#    Updated: 2020/01/25 12:54:21 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: 	all clean fclean re

COMPILER = clang
CFLAGS = -Wall -Wextra -Werror -o3 -march=native

LIBFT_PATH =	../../libft/
LIBFT_A =	libft.a
LIBFT = $(addprefix $(LIBFT_PATH),$(LIBFT_A))

FT_PRINTF_PATH = ../../ft_printf/
FT_PRINTF_A = libftprintf.a
FT_PRINTF = $(addprefix $(FT_PRINTF_PATH),$(FT_PRINTF_A))

SRC =		vm_valid_input.c		\
			vm_make_player_params.c	\
			vm_init_input.c			\
			vm_init_player.c		\
			vm_error.c				\
			vm_arena.c				\
			vm_print_map.c			\
			vm_print_players.c		\
			vm_make_start_list_cursor.c		\
			vm_print_cursor.c		\
			vm_no_print_map.c		\
			vm_do_cycle.c			\
			vm_init_t_dir.c			\
			vm_init_t_ind.c			\
			vm_init_args.c			\
			vm_init_cycle.c			\
			vm_dir_or_ind.c			\
			vm_move.c				\
			vm_validate_args.c		\
			vm_get_args.c			\
			vm_unfold_indirects.c	\
			vm_rewrite_map.c		\
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
			op_load.c				\
			op_load_i.c				\
			vm_check_cursor.c		\
			vm_lstdel_cursor.c		\
			vm_player_lst.c			\
			vm_print_log.c			\
			vm_get_flags.c			\
			vm_print_map_colors.c	\
			vm_print_map_static.c	\
			vm_print_map_dynamic.c	\
			vm.c

OBJ =		$(SRC:.c=.o)

HEADERS_NAMES =	vm.h defines.h vm_structs.h vm_print_map.h vm_init_player.h
HEADERS_PATH = ../../includes/
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAMES))

NAME =		../../corewar

all:		$(NAME)

$(NAME):	$(LIBFT) $(FT_PRINTF) $(OBJ) $(HEADERS)
			$(COMPILER) $(CFLAGS) -I $(HEADERS_PATH) -I $(LIBFT_PATH) -I $(FT_PRINTF_PATH) -g -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft -L $(FT_PRINTF_PATH) -lftprintf -lncurses

$(LIBFT):
			make -C $(LIBFT_PATH)

$(FT_PRINTF):
			make -C $(FT_PRINTF_PATH)

%.o:		%.c $(HEADERS)
			$(COMPILER) $(CFLAGS) -I $(LIBFT_PATH) -I $(FT_PRINTF_PATH) -I $(HEADERS_PATH) -g -c $< -o $@

clean:
			/bin/rm -f $(OBJ)

fclean:
			/bin/rm -f $(OBJ)
			/bin/rm -f $(NAME)

re:			fclean all
