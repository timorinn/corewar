/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expected_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:55:35 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 18:55:55 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_expexted_exit(t_all *gen, t_token *token, int i, ...)
{
	va_list	ap;
	int		a;
	int		f;

	f = 0;
	va_start(ap, i);
	print_point(token->point);
	ft_putstr(": Lexical error: \"");
	token->type == NL_TYPE ? ft_putstr("NEW LINE") : ft_putstr(token->content);
	ft_putstr("\"\n\tToken type: ");
	print_token_type(token->type);
	ft_putstr("\n\tExpected type: ");
	while (i)
	{
		if (f)
			ft_putstr(" or ");
		a = va_arg(ap, int);
		print_token_type(a);
		f = 1;
		i--;
	}
	ft_putchar('\n');
	va_end(ap);
	do_exit(NULL, gen);
}
