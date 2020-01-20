/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 12:26:33 by bford             #+#    #+#             */
/*   Updated: 2020/01/20 18:16:06 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_pr
{
	int				p;
	int				m;
	int				o;
	int				s;
	int				nol;
	int				i1;
	int				i1was;
	int				point;
	int				i2;
	int				i2was;
	int				f;
	char			c;
	int				all;
}					t_pf;

int					ft_printf(char *s, ...);
int					ft_start_work(char **s, va_list a, t_pf *l);
t_pf				*ft_lstnew_pf(void);
int					ft_postwork(t_pf **l, va_list a);
int					ft_pr(t_pf **l);
int					ft_c(t_pf **l, va_list a);
int					ft_s(t_pf **l, va_list a);
int					ft_s2(t_pf **l, char *s);
int					ft_d(t_pf **l, va_list a);
int					ft_o(t_pf **l, va_list a);
int					ft_d_func(t_pf **l, long long d);
int					ft_u(t_pf **l, va_list a);
int					ft_u_func(t_pf **l, unsigned long long u);
int					ft_putnbr_d(long long d, t_pf **l, int len);
int					ft_putnbr_u(unsigned long long d, t_pf **l, int len);
int					ft_clearlist(t_pf **l);
int					ft_nollist(t_pf **l);
int					ft_many_write(char c, int z, t_pf **l);
int					ft_lennbr_d(long long d, long long c);
int					ft_lennbr_u(unsigned long long d, unsigned long long c);
unsigned long long	ft_power(int num, int power);
int					ft_o(t_pf **l, va_list a);
int					ft_o_func(t_pf **l, unsigned long long o);
int					ft_putnbr_o(unsigned long long u, t_pf **l, int len);
int					ft_x(t_pf **l, va_list a);
int					ft_putnbr_x(unsigned long long x, t_pf **l,
int len, char big);
int					ft_x_func(t_pf **l, unsigned long long x);
int					ft_p(t_pf **l, va_list a);
void				ft_p_func(t_pf **l, unsigned long long p);
int					ft_f(t_pf **l, va_list a);
int					ft_f_func(t_pf **l, long double f);
int					ft_putnbr_f(long long second, t_pf **l, int second_len);
int					ft_putnbr_second(long long d, t_pf **l, int len);

#endif
