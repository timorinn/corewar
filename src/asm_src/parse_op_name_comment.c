/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_name_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:27:12 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 19:28:11 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	parse_op(t_all *gen, t_token *token)
{
	(!ft_strcmp(token->content, "live") ||
	!ft_strcmp(token->content, "fork") ||
	!ft_strcmp(token->content, "zjmp") ||
	!ft_strcmp(token->content, "lfork")) ?
		parse_live(gen, token) : 0;
	(!ft_strcmp(token->content, "ld") ||
	!ft_strcmp(token->content, "lld")) ?
		parse_ld(gen, token) : 0;
	!ft_strcmp(token->content, "st") ?
		parse_st(gen, token) : 0;
	(!ft_strcmp(token->content, "add") ||
	!ft_strcmp(token->content, "sub")) ?
		parse_add(gen, token) : 0;
	(!ft_strcmp(token->content, "and") ||
	!ft_strcmp(token->content, "or") ||
	!ft_strcmp(token->content, "xor")) ?
		parse_and(gen, token) : 0;
	(!ft_strcmp(token->content, "ldi") ||
	!ft_strcmp(token->content, "lldi")) ?
		parse_ldi(gen, token) : 0;
	!ft_strcmp(token->content, "sti") ?
		parse_sti(gen, token) : 0;
	!ft_strcmp(token->content, "aff") ?
		parse_aff(gen, token) : 0;
}

void	parse_name(t_all *gen, t_token *token)
{
	if (gen->name)
	{
		print_point(token->point);
		ft_putendl(": Lexical error:\n\tSecond name");
		do_exit(NULL, gen);
	}
	if (!is_equal_token_type(token->next, 1, NL_TYPE))
		print_expexted_exit(gen, token->next, 1, NL_TYPE);
	gen->name = 1;
	start_analyz(gen, next_token(token, 2));
}

void	parse_comment(t_all *gen, t_token *token)
{
	if (gen->comment)
	{
		print_point(token->point);
		ft_putendl(": Lexical error:\n\tSecond comment");
		do_exit(NULL, gen);
	}
	if (!is_equal_token_type(token->next, 1, NL_TYPE))
		print_expexted_exit(gen, token->next, 1, NL_TYPE);
	gen->comment = 1;
	start_analyz(gen, next_token(token, 2));
}
