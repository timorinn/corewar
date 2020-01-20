/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:12:02 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:08:09 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_make_i2(int len, t_pf **l)
{
	if (((*l)->i2 < 0) || (!(*l)->i2 && !(*l)->point && (*l)->nol))
		(*l)->i2 = (*l)->i1 - len;
	else if ((*l)->i2 < len)
		(*l)->i2 = 0;
	else
		(*l)->i2 -= len;
}

char	ft_make_sign_d(long long d, t_pf **l)
{
	char	sign;

	sign = (d < 0 ? '-' : 0);
	sign = (!sign && (*l)->p ? '+' : sign);
	sign = (!sign && (*l)->s ? ' ' : sign);
	return (sign);
}

void	ft_d_minus(int i1, int len, long long d, t_pf **l)
{
	int		i2;

	i2 = (*l)->i2;
	i2 = (i2 - len >= 0 ? i2 - len : 0);
	ft_many_write('0', i2, l);
	if (!(d == 0 && (*l)->point))
		ft_putnbr_d(d, l, len);
	ft_many_write(' ', i1 - i2 - len, l);
}

int		ft_d_func(t_pf **l, long long d)
{
	int		sign;
	int		len;

	len = (d == 0 && (*l)->point ? ft_lennbr_d(d, 10) - 1 : ft_lennbr_d(d, 10));
	sign = ft_make_sign_d(d, l);
	(*l)->m += (*l)->i1 < 0 && ((*l)->i1 *= -1) ? 1 : 0;
	(*l)->i1 -= (sign ? 1 : 0);
	(*l)->i1 = ((*l)->i1 - len < 0 ? len : (*l)->i1);
	if ((*l)->m)
	{
		if (sign)
			ft_many_write(sign, 1, l);
		ft_d_minus((*l)->i1, len, d, l);
	}
	else
	{
		ft_make_i2(len, l);
		ft_many_write(' ', (*l)->i1 - (*l)->i2 - len, l);
		if (sign)
			ft_many_write(sign, 1, l);
		ft_many_write('0', (*l)->i2, l);
		if (!(d == 0 && (*l)->point))
			ft_putnbr_d(d, l, len);
	}
	return (1);
}
