/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:18:57 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:08:46 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_d(long long d, t_pf **l, int len)
{
	long long	i;

	i = (d > 9 || d < -9 ? (long long)ft_power(10, len - 1) : 1);
	if (d < 0 && len > 1)
	{
		ft_many_write((d / i) * (-1) + '0', 1, l);
		d %= i;
		i /= 10;
	}
	d = (d < 0 ? -d : d);
	while (i)
	{
		ft_many_write(d / i + '0', 1, l);
		d %= i;
		i /= 10;
	}
	return (1);
}
