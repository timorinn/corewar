/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recording_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:56:25 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 19:57:17 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		op_reg_reg_reg(t_all *gen, t_token *token, char op_c)
{
	token->op_code = op_c;
	gen->size += 4;
	token->arg_code = (1 << 6) | (1 << 4) | (1 << 2);
	set_size_code(gen, next_token(token, 7));
	return (0);
}

int		op_regdirind_regdirind_reg(
	t_all *gen, t_token *token, char op_c, int dir_size)
{
	unsigned char	arg_1;
	unsigned char	arg_2;
	unsigned char	arg_3;

	gen->size++;
	token->op_code = op_c;
	arg_1 = set_arg_and_size(gen, next_token(token, 1), 6, dir_size);
	arg_2 = set_arg_and_size(gen, next_token(token, 3), 4, dir_size);
	arg_3 = set_arg_and_size(gen, next_token(token, 5), 2, dir_size);
	token->arg_code = arg_1 | arg_2 | arg_3;
	set_size_code(gen, next_token(token, 7));
	return (0);
}

int		op_regdirind_regdir_reg(
	t_all *gen, t_token *token, char op_c, int dir_size)
{
	unsigned char	arg_1;
	unsigned char	arg_2;
	unsigned char	arg_3;

	gen->size++;
	token->op_code = op_c;
	arg_1 = set_arg_and_size(gen, next_token(token, 1), 6, dir_size);
	arg_2 = set_arg_and_size(gen, next_token(token, 3), 4, dir_size);
	arg_3 = set_arg_and_size(gen, next_token(token, 5), 2, dir_size);
	token->arg_code = arg_1 | arg_2 | arg_3;
	set_size_code(gen, next_token(token, 7));
	return (0);
}

int		op_reg(t_all *gen, t_token *token, char op_c)
{
	gen->size += 2;
	token->op_code = op_c;
	token->arg_code = 1 << 6;
	set_size_code(gen, next_token(token, 3));
	return (0);
}

void	get_op_code(t_all *gen, t_token *token)
{
	!ft_strcmp(token->content, "live") ? op_dir(gen, token, 1, 4) : 0;
	!ft_strcmp(token->content, "ld") ? op_dirind_reg(gen, token, 2, 4) : 0;
	!ft_strcmp(token->content, "st") ? op_reg_regind(gen, token, 3) : 0;
	!ft_strcmp(token->content, "add") ? op_reg_reg_reg(gen, token, 4) : 0;
	!ft_strcmp(token->content, "sub") ? op_reg_reg_reg(gen, token, 5) : 0;
	!ft_strcmp(token->content, "and") ?
		op_regdirind_regdirind_reg(gen, token, 6, 4) : 0;
	!ft_strcmp(token->content, "or") ?
		op_regdirind_regdirind_reg(gen, token, 7, 4) : 0;
	!ft_strcmp(token->content, "xor") ?
		op_regdirind_regdirind_reg(gen, token, 8, 4) : 0;
	!ft_strcmp(token->content, "zjmp") ? op_dir(gen, token, 9, 2) : 0;
	!ft_strcmp(token->content, "ldi") ?
		op_regdirind_regdir_reg(gen, token, 10, 2) : 0;
	!ft_strcmp(token->content, "sti") ?
		op_reg_regdirind_regdir(gen, token, 11, 2) : 0;
	!ft_strcmp(token->content, "fork") ? op_dir(gen, token, 12, 2) : 0;
	!ft_strcmp(token->content, "lld") ? op_dirind_reg(gen, token, 13, 4) : 0;
	!ft_strcmp(token->content, "lldi") ?
		op_regdirind_regdir_reg(gen, token, 14, 2) : 0;
	!ft_strcmp(token->content, "lfork") ? op_dir(gen, token, 15, 2) : 0;
	!ft_strcmp(token->content, "aff") ? op_reg(gen, token, 16) : 0;
}
