# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 19:17:02 by swedde            #+#    #+#              #
#    Updated: 2020/01/31 19:59:10 by nsheev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: 	all clean fclean re

COMPILER = clang
CFLAGS = -Wall -Wextra -Werror -o3 -march=native

LIBFT_PATH =	../libft/
LIBFT_A =	libft.a
LIBFT = $(addprefix $(LIBFT_PATH),$(LIBFT_A))

FT_PRINTF_PATH = ../ft_printf/
FT_PRINTF_A = libftprintf.a
FT_PRINTF = $(addprefix $(FT_PRINTF_PATH),$(FT_PRINTF_A))

SRC =		set_def_gen.c			\
			write_int_to_file.c		\
			do_exit.c 				\
			reading.c				\
			t_token_func.c 			\
			char_to_string.c 		\
			print_point.c 			\
			lexical_analyz.c 		\
			recording.c 			\
			write_short_to_file.c 	\
			write_byte_to_file.c 	\
			write_nam_com_to_file.c	\
			main.c					\
			is_equal_token_type.c	\
			next_token.c 			\
			parse_op_name_comment.c	\
			print_expected_exit.c	\
			print_token_type.c		\
			switch_parse_1.c		\
			switch_parse_2.c		\
			recording_1.c			\
			recording_2.c			

HEAD =		asm.h

OBJ =		$(SRC:.c=.o)

NAME =		../asm

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(FT_PRINTF)
			$(COMPILER) $(CFLAGS) $(OBJ) -L ../libft -lft -o $(NAME)

$(LIBFT):
			make -C $(LIBFT_PATH)

$(FT_PRINTF):
			make -C $(FT_PRINTF_PATH)

%.o:		%.c $(HEAD)
			$(COMPILER) $(CFLAGS) -I ./ -g -c $< -o $@

clean:
			/bin/rm -f $(OBJ)

fclean: 	clean
			/bin/rm -f $(NAME)

re: 		fclean all
