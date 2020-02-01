/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal_token_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:57:30 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 18:57:47 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		is_equal_token_type(t_token *token, int i, ...)
{
	int		a;
	va_list	ap;

	if (!token)
		return (0);
	va_start(ap, i);
	while (i)
	{
		a = va_arg(ap, int);
		if (token->type == a)
		{
			va_end(ap);
			return (1);
		}
		i--;
	}
	va_end(ap);
	return (0);
}
