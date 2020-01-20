/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:21:19 by bford             #+#    #+#             */
/*   Updated: 2019/10/03 18:31:16 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_u(unsigned long long u, t_pf **l, int len)
{
	unsigned long long	i;

	i = (u > 9 ? (unsigned long long)ft_power(10, len - 1) : 1);
	while (i)
	{
		ft_many_write(u / i + '0', 1, l);
		u %= i;
		i /= 10;
	}
	return (1);
}
