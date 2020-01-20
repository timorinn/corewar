/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:45:31 by bford             #+#    #+#             */
/*   Updated: 2019/10/02 19:53:13 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_o(unsigned long long u, t_pf **l, int len)
{
	unsigned long long	i;

	i = (u > 7 ? (unsigned long long)ft_power(8, len - 1) : 1);
	while (i)
	{
		ft_many_write(u / i + '0', 1, l);
		u %= i;
		i /= 8;
	}
	return (1);
}
