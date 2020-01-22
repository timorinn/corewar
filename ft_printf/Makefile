# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 11:34:46 by bford             #+#    #+#              #
#    Updated: 2020/01/22 11:45:25 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

SRC =				ft_c.c ft_clearlist.c 		\
					ft_d_func.c ft_d.c 			\
					ft_f_func.c 				\
					ft_f.c 						\
					ft_lennbr_d.c 				\
					ft_lennbr_u.c				\
					ft_lstnew_pf.c				\
					ft_many_write.c				\
					ft_nollist.c				\
					ft_o_func.c ft_o.c			\
					ft_p_func.c					\
					ft_p.c						\
					ft_postwork.c				\
					ft_power.c					\
					ft_pr.c						\
					ft_printf.c					\
					ft_putnbr_d.c				\
					ft_putnbr_f.c				\
					ft_putnbr_o.c				\
					ft_putnbr_second.c			\
					ft_putnbr_u.c				\
					ft_putnbr_x.c				\
					ft_s.c						\
					ft_s2.c						\
					ft_start_work.c				\
					ft_u_func.c					\
					ft_u.c						\
					ft_x_func.c					\
					ft_x.c

OBJ =		$(SRC:.c=.o)

HEAD =		ft_printf.h

NAME =		libftprintf.a

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