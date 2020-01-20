/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:01:40 by bford             #+#    #+#             */
/*   Updated: 2020/01/20 18:05:54 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s)
{
	int		len;

	len = (int)ft_strlen(s);
	if (s)
		write(1, s, len);
	return (len);
}
