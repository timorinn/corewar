/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:41:20 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:07:57 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_o_no_minus(int i1, int len, t_pf **l, unsigned long long o)
{
	int		i2;

	i2 = (*l)->i2;
	if ((i2 < 0) || (!i2 && !(*l)->point && (*l)->nol))
		i2 = (*l)->i1 - len;
	else if (i2 < len)
		i2 = 0;
	else
		i2 -= len;
	ft_many_write(' ', i1 - i2 - len, l);
	(*l)->o && o ? ft_many_write('0', 1, l) : 0;
	ft_many_write('0', i2 - ((*l)->o > 0), l);
	if (!(o == 0 && (*l)->point) || (*l)->o)
		ft_putnbr_o(o, l, len);
}

void	ft_o_minus(int i1, int len, t_pf **l, unsigned long long o)
{
	int		i2;

	i2 = (*l)->i2;
	i2 = (i2 - len >= 0 ? i2 - len : 0);
	ft_many_write('0', i2, l);
	(*l)->o && o ? ft_many_write('0', 1, l) : 0;
	if (!(o == 0 && (*l)->point))
		ft_putnbr_o(o, l, len);
	ft_many_write(' ', i1 - i2 - len, l);
}

int		ft_o_func(t_pf **l, unsigned long long o)
{
	int		len;
	int		i1;

	i1 = (*l)->i1;
	len = (o == 0 && (*l)->point ? ft_lennbr_u(o, 8) - 1 : ft_lennbr_u(o, 8));
	if (i1 < 0 && (i1 *= -1))
		(*l)->m += 1;
	i1 = (i1 - len < 0 ? len : i1);
	i1 -= ((*l)->o && o ? 1 : 0);
	if ((*l)->m)
		ft_o_minus(i1, len, l, o);
	else
		ft_o_no_minus(i1, len, l, o);
	return (1);
}
