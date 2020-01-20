/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:08:59 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:08:56 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_second(long long d, t_pf **l, int len)
{
	long long	i;

	i = (long long)ft_power(10, len - 1);
	if (i < d)
		d = d % (i * 10);
	if (i == 10)
		i = 1;
	while (i)
	{
		ft_many_write(d / i + '0', 1, l);
		d %= i;
		i /= 10;
	}
	return (1);
}
