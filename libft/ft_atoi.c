/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:52:30 by bford             #+#    #+#             */
/*   Updated: 2020/01/27 19:52:32 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	unsigned long long int	n;
	unsigned long long		border;
	int						sign;

	sign = 1;
	n = 0;
	border = (unsigned long long)(9223372036854775807 / 10);
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
		sign *= (*s++ == '-' ? -1 : 1);
	while (ft_isdigit(*s))
	{
		if ((n > border || (n == border && *s > '7')) && sign == 1)
			return (-1);
		else if ((n > border || (n == border && *s > '8')) && sign == -1)
			return (0);
		n = n * 10 + (*s++) - 48;
	}
	return (n * sign);
}
