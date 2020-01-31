/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_parse_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:06:20 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 19:08:20 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_ldi(t_all *gen, t_token *token)
{
	if (!is_equal_token_type(next_token(token, 1), 5, REG_ARG_TYPE,
	IND_ARG_TYPE, IND_LABL_ARG_TYPE, DIR_ARG_TYPE, DIR_LABL_ARG_TYPE))
		print_expexted_exit(gen, next_token(token, 1), 3, REG_ARG_TYPE,
		IND_ARG_TYPE, DIR_ARG_TYPE);
	if (!is_equal_token_type(next_token(token, 2), 1, DELIM_TYPE))
		print_expexted_exit(gen, next_token(token, 2), 1, DELIM_TYPE);
	if (!is_equal_token_type(next_token(token, 3), 3, REG_ARG_TYPE,
	DIR_ARG_TYPE, DIR_LABL_ARG_TYPE))
		print_expexted_exit(gen, next_token(token, 3), 3, REG_ARG_TYPE,
		DIR_ARG_TYPE);
	if (!is_equal_token_type(next_token(token, 4), 1, DELIM_TYPE))
		print_expexted_exit(gen, next_token(token, 4), 1, DELIM_TYPE);
	if (!is_equal_token_type(next_token(token, 5), 1, REG_ARG_TYPE))
		print_expexted_exit(gen, next_token(token, 5), 1, REG_ARG_TYPE);
	if (!is_equal_token_type(next_token(token, 6), 1, NL_TYPE))
		print_expexted_exit(gen, next_token(token, 6), 1, NL_TYPE);
	start_analyz(gen, next_token(token, 7));
}

void	parse_sti(t_all *gen, t_token *token)
{
	if (!is_equal_token_type(next_token(token, 1), 1, REG_ARG_TYPE))
		print_expexted_exit(gen, next_token(token, 1), 1, REG_ARG_TYPE);
	if (!is_equal_token_type(next_token(token, 2), 1, DELIM_TYPE))
		print_expexted_exit(gen, next_token(token, 2), 1, DELIM_TYPE);
	if (!is_equal_token_type(next_token(token, 3), 5, REG_ARG_TYPE,
	IND_ARG_TYPE, IND_LABL_ARG_TYPE, DIR_ARG_TYPE, DIR_LABL_ARG_TYPE))
		print_expexted_exit(gen, next_token(token, 3), 3, REG_ARG_TYPE,
		IND_ARG_TYPE, DIR_ARG_TYPE);
	if (!is_equal_token_type(next_token(token, 4), 1, DELIM_TYPE))
		print_expexted_exit(gen, next_token(token, 4), 1, DELIM_TYPE);
	if (!is_equal_token_type(next_token(token, 5), 3, REG_ARG_TYPE,
	DIR_ARG_TYPE, DIR_LABL_ARG_TYPE))
		print_expexted_exit(gen, next_token(token, 5), 2, REG_ARG_TYPE,
		DIR_ARG_TYPE);
	if (!is_equal_token_type(next_token(token, 6), 1, NL_TYPE))
		print_expexted_exit(gen, next_token(token, 6), 1, NL_TYPE);
	start_analyz(gen, next_token(token, 7));
}

void	parse_aff(t_all *gen, t_token *token)
{
	if (!is_equal_token_type(next_token(token, 1), 1, REG_ARG_TYPE))
		print_expexted_exit(gen, next_token(token, 1), 1, REG_ARG_TYPE);
	if (!is_equal_token_type(next_token(token, 2), 1, NL_TYPE))
		print_expexted_exit(gen, next_token(token, 2), 1, NL_TYPE);
	start_analyz(gen, next_token(token, 3));
}
