/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:48:18 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 14:59:49 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_x(unsigned long long x, t_pf **l, int len, char big)
{
	unsigned long long	i;
	unsigned long long	res;

	big = (big == 120 ? 87 : 55);
	i = (x > 15 ? (unsigned long long)ft_power(16, len - 1) : 1);
	while (i)
	{
		res = x / i;
		res = (res > 9 ?
		ft_many_write(res + big, 1, l) : ft_many_write(res + '0', 1, l));
		x %= i;
		i /= 16;
	}
	return (1);
}
