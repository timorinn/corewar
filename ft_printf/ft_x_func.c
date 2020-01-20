/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:47:43 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:08:06 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x_no_minus(int i1, int len, t_pf **l, unsigned long long x)
{
	int		i2;

	i2 = (*l)->i2;
	if ((i2 < 0) || (!i2 && !(*l)->point && (*l)->nol))
		i2 = i1 - len;
	else if (i2 < len)
		i2 = 0;
	else
		i2 -= len;
	ft_many_write(' ', i1 - i2 - len, l);
	(*l)->o && x ?
	ft_many_write('0', 1, l) && ft_many_write((*l)->c, 1, l) : 0;
	ft_many_write('0', i2, l);
	if (!(x == 0 && (*l)->point))
		ft_putnbr_x(x, l, len, (*l)->c);
}

void	ft_x_minus(int i1, int len, t_pf **l, unsigned long long x)
{
	int		i2;

	i2 = (*l)->i2;
	i2 = (i2 - len >= 0 ? i2 - len : 0);
	ft_many_write('0', i2, l);
	(*l)->o && x ? ft_many_write('0', 1, l) &&
	ft_many_write((*l)->c, 1, l) : 0;
	if (!(x == 0 && (*l)->point))
		ft_putnbr_x(x, l, len, (*l)->c);
	ft_many_write(' ', i1 - i2 - len, l);
}

int		ft_x_func(t_pf **l, unsigned long long x)
{
	int		len;
	int		i1;

	i1 = (*l)->i1;
	len = (x == 0 && (*l)->point ? ft_lennbr_u(x, 16) - 1 : ft_lennbr_u(x, 16));
	if (i1 < 0 && (i1 *= -1))
		(*l)->m += 1;
	i1 = (i1 - len < 0 ? len : i1);
	i1 -= ((*l)->o && x ? 2 : 0);
	if ((*l)->m)
		ft_x_minus(i1, len, l, x);
	else
		ft_x_no_minus(i1, len, l, x);
	return (1);
}
