/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_postwork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:19:35 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 18:08:33 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

int		ft_postwork(t_pf **l, va_list a)
{
	char	spec;

	spec = (*l)->c;
	if ((!spec) || ((spec == 'x' || spec == 'X') && ft_x(l, a)) ||
	((spec == 'd' || spec == 'i') && ft_d(l, a)) ||
	(spec == 'c' && ft_c(l, a)) || (spec == 's' && ft_s(l, a)) ||
	(spec == '%' && ft_pr(l)) || (spec == 'u' && ft_u(l, a)) ||
	(spec == 'o' && ft_o(l, a)) || (spec == 'p' && ft_p(l, a)) ||
	(spec == 'f' && ft_f(l, a)))
		return (ft_nollist(l));
	return (0);
}
