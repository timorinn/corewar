/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recording_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:48:59 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 19:55:12 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		set_arg_and_size(t_all *gen, t_token *tmp, int move, int dir_size)
{
	int		arg;

	arg = 0;
	if (tmp->type == REG_ARG_TYPE)
	{
		arg = 1;
		gen->size++;
	}
	else if (tmp->type == DIR_ARG_TYPE || tmp->type == DIR_LABL_ARG_TYPE)
	{
		tmp->size = gen->op_size;
		tmp->dir_size = dir_size;
		gen->size += dir_size;
		arg = 2;
	}
	else
	{
		tmp->size = gen->op_size;
		gen->size += 2;
		arg = 3;
	}
	return (arg << move);
}

int		op_dir(t_all *gen, t_token *token, char op_c, int dir_size)
{
	token->op_code = op_c;
	token->arg_code = 0;
	gen->size += dir_size;
	token->next->dir_size = dir_size;
	token->next->size = gen->op_size;
	set_size_code(gen, next_token(token, 3));
	return (0);
}

int		op_dirind_reg(t_all *gen, t_token *token, char op_c, int dir_size)
{
	unsigned char	arg_1;
	unsigned char	arg_2;

	gen->size++;
	token->op_code = op_c;
	arg_1 = set_arg_and_size(gen, next_token(token, 1), 6, dir_size);
	arg_2 = set_arg_and_size(gen, next_token(token, 3), 4, dir_size);
	token->arg_code = arg_1 | arg_2;
	set_size_code(gen, next_token(token, 5));
	return (0);
}

int		op_reg_regdirind_regdir(
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

int		op_reg_regind(t_all *gen, t_token *token, char op_c)
{
	unsigned char	arg_1;
	unsigned char	arg_2;

	gen->size++;
	token->op_code = op_c;
	arg_1 = set_arg_and_size(gen, next_token(token, 1), 6, 0);
	arg_2 = set_arg_and_size(gen, next_token(token, 3), 4, 0);
	token->arg_code = arg_1 | arg_2;
	set_size_code(gen, next_token(token, 5));
	return (0);
}
