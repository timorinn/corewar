/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lennbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:10:29 by bford             #+#    #+#             */
/*   Updated: 2019/10/06 14:34:30 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lennbr_u(unsigned long long d, unsigned long long c)
{
	int	len;

	len = 1;
	while (d /= c)
		len++;
	return (len);
}
