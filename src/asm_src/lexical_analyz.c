/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 22:58:42 by swedde            #+#    #+#             */
/*   Updated: 2020/01/31 19:28:09 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	start_analyz(t_all *gen, t_token *token)
{
	if (!token || (gen->name && gen->comment && token->type == END_FILE))
		return ;
	if (token->type == NL_TYPE)
		start_analyz(gen, token->next);
	else if (token->type == NAME_TYPE)
		parse_name(gen, token);
	else if (token->type == COMMENT_TYPE)
		parse_comment(gen, token);
	else if (gen->name && gen->comment)
	{
		if (token->type == LABEL_TYPE)
			token->next->type != END_FILE ? start_analyz(gen, token->next)
			: print_expexted_exit(gen, token, 1, NL_TYPE);
		else if (token->type == OP_TYPE)
			parse_op(gen, token);
		else
			print_expexted_exit(gen, token, 2, LABEL_TYPE, OP_TYPE);
	}
	else if (gen->name)
		print_expexted_exit(gen, token, 1, COMMENT_TYPE);
	else if (gen->comment)
		print_expexted_exit(gen, token, 1, NAME_TYPE);
	else
		print_expexted_exit(gen, token, 2, NAME_TYPE, COMMENT_TYPE);
}

int		is_exist_label(t_token *token, char *s)
{
	while (token)
	{
		if (token->type == LABEL_TYPE && !ft_strcmp(token->content, s))
			return (1);
		token = token->next;
	}
	return (0);
}

void	print_nonexist_label_exit(t_all *gen, t_token *token)
{
	print_point(token->point);
	ft_putstr(": Lexical error:\n\tNonexistent label reference\n");
	do_exit(NULL, gen);
}

void	check_nonexist_labels(t_all *gen)
{
	t_token *token;

	token = gen->token;
	while (token)
	{
		if (token->type == IND_LABL_ARG_TYPE ||
		token->type == DIR_LABL_ARG_TYPE)
			if (!is_exist_label(gen->token, token->content))
				print_nonexist_label_exit(gen, token);
		token = token->next;
	}
}

void	lexical_analyz(t_all *gen)
{
	start_analyz(gen, gen->token);
	check_nonexist_labels(gen);
}
