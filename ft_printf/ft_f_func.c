/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:25:59 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:08:07 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_make_sign_f(long double f, t_pf **l)
{
	char sign;

	sign = (f < 0 ? '-' : 0);
	sign = (!sign && (*l)->p ? '+' : sign);
	sign = (!sign && (*l)->s ? ' ' : sign);
	return (sign);
}

void	ft_f_no_minus(long double f, t_pf **l,
long long first, long double second)
{
	ft_putnbr_d(f, l, first);
	if (!(*l)->point || ((*l)->point && ((*l)->i2 || (*l)->o)))
		ft_many_write('.', 1, l);
	if ((*l)->i2)
		ft_putnbr_second(second, l, (*l)->i2);
}

void	ft_f_minus(long double f, t_pf **l,
long long first, long double second)
{
	ft_putnbr_d(f, l, first);
	if (!(*l)->point || ((*l)->point && ((*l)->i2 || (*l)->o)))
		ft_many_write('.', 1, l);
	if ((*l)->i2)
		ft_putnbr_second(second, l, (*l)->i2);
	ft_many_write(' ', (*l)->i1, l);
}

void	ft_make_second(long double *second, int i2, long double *f)
{
	if (*f < 0 && ((long long)(*second * 10)) % 10 <= -5)
	{
		*second -= 1.0;
		if (-1 * (long long)(*second) % ft_power(10, i2) == 0)
			(*f)--;
	}
	else if (((long long)(*second * 10)) % 10 >= 5)
	{
		*second += 1.0;
		if ((long long)(*second) % ft_power(10, i2) == 0)
			(*f)++;
	}
	*second *= (*second < 0 ? -1 : 1);
}

int		ft_f_func(t_pf **l, long double f)
{
	long double second;
	char		sign;

	(*l)->i2 = ((*l)->i2 || (!(*l)->i2 && (*l)->point) ? (*l)->i2 : 6);
	sign = ft_make_sign_f(f, l);
	second = ((*l)->i2 ?
	(f - (long double)((long long)f)) * ft_power(10, (*l)->i2 + 1) / 10 : 0);
	f += (*l)->point && !(*l)->i2 && ((int)(f * 10.0) % 10 >= 5) ? 1 : 0;
	f -= (*l)->point && !(*l)->i2 && ((int)(f * 10.0) % 10 <= -5) ? 1 : 0;
	ft_make_second(&second, (*l)->i2, &f);
	(*l)->i1 -= (!(*l)->point || ((*l)->point && (*l)->i2) ? 1 : 0);
	(*l)->i1 -= (*l)->point + (*l)->i2 + (sign > 0);
	if ((*l)->m)
	{
		sign ? ft_many_write(sign, 1, l) : 0;
		ft_f_minus(f, l, ft_lennbr_d(f, 10), second);
	}
	else
	{
		ft_many_write((*l)->nol ? '0' : ' ', (*l)->i1, l);
		sign ? ft_many_write(sign, 1, l) : 0;
		ft_f_no_minus(f, l, ft_lennbr_d(f, 10), second);
	}
	return (1);
}
