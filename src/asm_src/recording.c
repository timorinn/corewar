/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recording.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 00:11:50 by swedde            #+#    #+#             */
/*   Updated: 2020/01/31 19:59:13 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		set_op_size(t_all *gen, t_token *token)
{
	token->size = gen->size;
	gen->op_size = gen->size;
	gen->size++;
	get_op_code(gen, token);
	return (0);
}

void	set_size_code(t_all *gen, t_token *token)
{
	if (token->type == END_FILE)
		return ;
	else if (token->type == LABEL_TYPE)
	{
		token->size = gen->size;
		set_size_code(gen, token->next);
	}
	else if (token->type == OP_TYPE)
		set_op_size(gen, token);
	else
		set_size_code(gen, token->next);
}

int		get_label_value(t_token *start, t_token *token)
{
	while (start)
	{
		if (start->type == LABEL_TYPE &&
		!ft_strcmp(start->content, token->content))
			return (start->size - token->size);
		start = start->next;
	}
	return (0);
}

void	write_exec_code_to_file(t_all *gen, t_token *token)
{
	while (token)
	{
		if (token->type == OP_TYPE && write_byte_to_file(gen, token->op_code))
			token->arg_code ? write_byte_to_file(gen, token->arg_code) : 0;
		else if (token->type == REG_ARG_TYPE)
			write_byte_to_file(gen, (unsigned char)ft_atoi(token->content));
		else if (token->type == DIR_ARG_TYPE)
			if (token->dir_size == 2)
				write_short_to_file(gen, (short)ft_atoi(token->content));
			else
				write_int_to_file(gen, ft_atoi(token->content));
		else if (token->type == DIR_LABL_ARG_TYPE)
			if (token->dir_size == 2)
				write_short_to_file(gen,
				(short)get_label_value(gen->token, token));
			else
				write_int_to_file(gen, get_label_value(gen->token, token));
		else if (token->type == IND_ARG_TYPE)
			write_short_to_file(gen, (short)ft_atoi(token->content));
		else if (token->type == IND_LABL_ARG_TYPE)
			write_short_to_file(gen, get_label_value(gen->token, token));
		token = token->next;
	}
}

void	recording(t_all *gen)
{
	if ((gen->fd = open(gen->file_name, O_RDWR | O_CREAT | O_TRUNC, 0777))
	== -1)
	{
		ft_putendl("Error: Failed to create file");
		do_exit(NULL, gen);
	}
	set_size_code(gen, gen->token);
	write_int_to_file(gen, COREWAR_EXEC_MAGIC);
	write_nam_com_to_file(gen, PROG_NAME_LENGTH, NAME_TYPE);
	write_int_to_file(gen, gen->size);
	write_nam_com_to_file(gen, COMMENT_LENGTH, COMMENT_TYPE);
	write_exec_code_to_file(gen, gen->token);
	ft_putstr("Writing output program to ");
	ft_putendl(gen->file_name);
	close(gen->fd);
}
