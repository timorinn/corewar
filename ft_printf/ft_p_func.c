/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:05:58 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:08:27 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_func(t_pf **l, unsigned long long p)
{
	int		len;
	int		i2copy;

	i2copy = (*l)->i2;
	len = ft_lennbr_u(p, 16);
	(*l)->m += ((*l)->i1 < 0 && ((*l)->i1 *= -1) ? 1 : 0);
	(*l)->i1 = ((*l)->i1 - len < 0 ? len : (*l)->i1);
	if ((*l)->m)
	{
		(*l)->i2 = ((*l)->i2 - len >= 0 ? (*l)->i2 - len : 0);
		(*l)->all += ft_putstr("0x");
		ft_many_write('0', (*l)->i2 - 4, l);
		ft_putnbr_x(p, l, len, 'x');
		ft_many_write(' ', (*l)->i1 - (*l)->i2 - len - 2, l);
	}
	else
	{
		(*l)->i2 = ((*l)->i2 - len >= 0 ? (*l)->i2 - len : 0);
		(*l)->i2 = ((*l)->nol && !((*l)->i2) ? (*l)->i1 - len : (*l)->i2);
		ft_many_write(' ', (*l)->i1 - (*l)->i2 - len - 2, l);
		(*l)->all += ft_putstr("0x");
		ft_many_write('0', (*l)->i2, l);
		if (!(p == 0 && !i2copy && (*l)->point))
			ft_putnbr_x(p, l, len, 'x');
	}
}
