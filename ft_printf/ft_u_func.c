/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:34:46 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 16:53:48 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_no_minus(t_pf **l, int i1, int len, unsigned long long u)
{
	int	i2;

	i2 = (*l)->i2;
	if ((i2 < 0) || (!i2 && !(*l)->point && (*l)->nol))
		i2 = i1 - len;
	else if (i2 < len)
		i2 = 0;
	else
		i2 -= len;
	ft_many_write(' ', (*l)->i1 - i2 - len, l);
	ft_many_write('0', i2, l);
	if (!(u == 0 && (*l)->point))
		ft_putnbr_u(u, l, len);
}

void	ft_u_minus(t_pf **l, int i1, int len, unsigned long long u)
{
	int i2;

	i2 = (*l)->i2;
	i2 = (i2 - len >= 0 ? i2 - len : 0);
	ft_many_write('0', i2, l);
	if (!(u == 0 && (*l)->point))
		ft_putnbr_u(u, l, len);
	ft_many_write(' ', i1 - i2 - len, l);
}

int		ft_u_func(t_pf **l, unsigned long long u)
{
	int		len;
	int		i1;

	i1 = (*l)->i1;
	len = (u == 0 && (*l)->point ? ft_lennbr_u(u, 10) - 1 : ft_lennbr_u(u, 10));
	if (i1 < 0 && (i1 *= -1))
		(*l)->m += 1;
	i1 = (i1 - len < 0 ? len : i1);
	if ((*l)->m)
		ft_u_minus(l, i1, len, u);
	else
		ft_u_no_minus(l, i1, len, u);
	return (1);
}
