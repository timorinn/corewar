/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndupu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:24:27 by bford             #+#    #+#             */
/*   Updated: 2019/12/06 12:26:35 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

unsigned char	*ft_strndupu(char const *src, int n)
{
	unsigned char	*s;
	int				len;

	len = n;
	if (!src || n < 0)
		return (NULL);
	if ((s = (unsigned char *)malloc(sizeof(unsigned char) * (n + 1))) == 0)
		return (NULL);
	while (n--)
		*s++ = *src++;
	*s = '\0';
	s -= len;
	return (s);
}
