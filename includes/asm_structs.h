/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:30:35 by kpsylock          #+#    #+#             */
/*   Updated: 2020/02/01 18:30:38 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCTS_H
# define ASM_STRUCTS_H

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_token
{
	int				type;
	char			*content;
	t_point			point;
	int				size;
	unsigned char	op_code;
	unsigned char	arg_code;
	int				dir_size;
	struct s_token	*next;
}					t_token;

union				u_int
{
	unsigned		a;
	struct			s_ch
	{
		unsigned char	c1:8;
		unsigned char	c2:8;
		unsigned char	c3:8;
		unsigned char	c4:8;
	}				t_ch;
};

typedef union		u_short
{
	unsigned short	a;
	struct			s_sch
	{
		unsigned char	c1:8;
		unsigned char	c2:8;
	}				t_sch;
}					t_short;

typedef struct		s_all
{
	int				i;
	char			*file;
	t_point			point;
	t_token			*token;
	int				fd;
	int				fd_s;
	char			*file_name;
	char			*error;
	int				name;
	int				comment;
	int				size;
	int				op_size;
}					t_all;

#endif
