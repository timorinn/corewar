/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:48:47 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:09:13 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x(t_pf **l, va_list a)
{
	int		flag;

	flag = (*l)->f;
	if ((flag == 0 &&
	ft_x_func(l, (unsigned int)va_arg(a, unsigned long long))) ||
	(flag == 1 &&
	ft_x_func(l, (unsigned char)va_arg(a, unsigned long long))) ||
	(flag == 2 &&
	ft_x_func(l, (unsigned long long)va_arg(a, unsigned long long))) ||
	(flag == 3 &&
	ft_x_func(l, (unsigned short)va_arg(a, unsigned long long))) ||
	(flag == 4 &&
	ft_x_func(l, (unsigned long)va_arg(a, unsigned long long))))
		return (1);
	return (0);
}
