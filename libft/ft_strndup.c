/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:55:25 by bford             #+#    #+#             */
/*   Updated: 2019/12/05 19:13:05 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(char const *src, int n)
{
	char	*s;
	int		len;

	len = n;
	if (!src || n < 0)
		return (NULL);
	if ((s = (char *)malloc(sizeof(char) * (n + 1))) == 0)
		return (NULL);
	while (n--)
		*s++ = *src++;
	*s = '\0';
	s -= len;
	return (s);
}
