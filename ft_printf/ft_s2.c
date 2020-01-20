/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:31:08 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 15:38:20 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s2(t_pf **l, char *s)
{
	int		len;
	int		i1;
	int		i2;

	i1 = (*l)->i1;
	i2 = (*l)->i2;
	len = (int)ft_strlen(s);
	i2 = (i2 < 0 ? len : i2);
	len = ((*l)->point == 1 && len > i2 ? i2 : len);
	len = ((*l)->point == 1 && !((*l)->i2was) ? 0 : len);
	(*l)->m += (i1 < 0 ? 1 : 0);
	i1 *= (i1 < 0 ? -1 : 1);
	if ((*l)->m)
	{
		(*l)->all += ft_putstr_num(s, len);
		if ((*l)->i1was && i1 > 0 && i1 > len)
			ft_many_write(' ', i1 - len, l);
	}
	else if (!(*l)->m)
	{
		if ((*l)->i1was && i1 >= 0 && i1 > len)
			ft_many_write(' ', i1 - len, l);
		(*l)->all += ft_putstr_num(s, len);
	}
	return (1);
}
