/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:19:36 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 14:43:27 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_o(t_pf **l, va_list a)
{
	t_pf	*lst;

	lst = *l;
	if ((lst->f == 0 &&
	ft_o_func(l, (unsigned int)va_arg(a, unsigned long long))) ||
	(lst->f == 1 &&
	ft_o_func(l, (unsigned char)va_arg(a, unsigned long long))) ||
	(lst->f == 2 &&
	ft_o_func(l, (unsigned long long)va_arg(a, unsigned long long))) ||
	(lst->f == 4 &&
	ft_o_func(l, (unsigned long)va_arg(a, unsigned long))) ||
	(lst->f == 3 &&
	ft_o_func(l, (unsigned short)va_arg(a, unsigned long long))))
		return (1);
	return (0);
}
