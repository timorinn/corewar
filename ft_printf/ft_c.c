/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:49:45 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:07:59 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int		ft_c(t_pf **l, va_list a)
{
	int		width;
	int		minus;
	t_pf	*lst;

	lst = *l;
	width = (*l)->i1;
	minus = (*l)->m || (width < 0);
	if (lst->p || lst->f || lst->point > 1)
		return (0);
	width *= (width + (width == 0) < 0 ? -1 : 1);
	if ((minus && ft_many_write(va_arg(a, int), 1, l) &&
	ft_many_write(' ', width - 1, l)) ||
	(!minus && ft_many_write(' ', width - 1, l) &&
	ft_many_write(va_arg(a, int), 1, l)))
		return (1);
	return (0);
}
