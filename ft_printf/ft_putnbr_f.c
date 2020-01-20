/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:58:36 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:08:53 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_f(long long second, t_pf **l, int second_len)
{
	if (second_len--)
		ft_putnbr_f(second / 10, l, second_len);
	ft_many_write(second % 10 + '0', 1, l);
	return (1);
}
