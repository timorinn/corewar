/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:22:50 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:07:55 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_f(t_pf **l, va_list a)
{
	int		flag;

	flag = (*l)->f;
	if ((flag == 0 && ft_f_func(l, (long double)va_arg(a, double))) ||
	(flag == 4 && ft_f_func(l, (long double)va_arg(a, double))) ||
	(flag == 5 &&
	ft_f_func(l, (long double)va_arg(a, long double))))
		return (1);
	return (0);
}
