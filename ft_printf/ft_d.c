/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:35:26 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:08:10 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_d(t_pf **l, va_list a)
{
	int		flag;

	flag = (*l)->f;
	if (!((*l)->o) &&
	(((flag == 0) && ft_d_func(l, (int)(va_arg(a, long long)))) ||
	((flag == 1) && ft_d_func(l, (char)(va_arg(a, long long)))) ||
	((flag == 2) && ft_d_func(l, (long long)(va_arg(a, long long)))) ||
	((flag == 3) && ft_d_func(l, (short)(va_arg(a, long long)))) ||
	((flag == 4) && ft_d_func(l, (long)(va_arg(a, long long))))))
		return (1);
	return (0);
}
