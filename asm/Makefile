# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 19:17:02 by swedde            #+#    #+#              #
#    Updated: 2020/01/24 21:09:44 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		asm

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
			main.c

HEAD =		asm.h

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -Wall -Wextra -Werror $(OBJ) -L ../libft -lft -o asm

%.o:		%.c $(HEAD)
			gcc -I ./ -Wall -Wextra -Werror -g -c $< -o $@

clean:
			/bin/rm -f *.o

fclean: 	clean
			/bin/rm -f $(NAME)

re: 		fclean all
