/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 12:02:56 by bford             #+#    #+#             */
/*   Updated: 2020/01/20 18:18:04 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_printf(char *s, ...)
{
	va_list	a;
	t_pf	*l;
	int		len;

	l = ft_lstnew_pf();
	va_start(a, s);
	while (*s)
	{
		if (*s == '%')
		{
			if (!ft_start_work(&s, a, l))
				return (-ft_clearlist(&l));
			continue;
		}
		ft_many_write(*s, 1, &l);
		s++;
	}
	len = l->all;
	ft_clearlist(&l);
	va_end(a);
	return (len);
}
