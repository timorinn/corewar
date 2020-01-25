/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:48:57 by swedde            #+#    #+#             */
/*   Updated: 2020/01/25 16:47:43 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	do_free(t_all *gen)
{
	ft_strdel(&gen->file_name);
	lst_del_token(gen->token);
	ft_strdel(&gen->file);
	free(gen);
}

void	check_constant_helper(t_all *gen, t_token *token)
{
	print_point(token->point);
	ft_putstr(": Constant error:\n\t");
	print_token_type(token->type);
	ft_putendl(" size exceeded");
	do_exit(NULL, gen);
}

void	check_constant(t_all *gen)
{
	t_token *token;

	token = gen->token;
	while (token->type != NAME_TYPE)
		token = token->next;
	if (ft_strlen(token->content) > PROG_NAME_LENGTH)
		check_constant_helper(gen, token);
	token = gen->token;
	while (token->type != COMMENT_TYPE)
		token = token->next;
	if (ft_strlen(token->content) > COMMENT_LENGTH)
		check_constant_helper(gen, token);
}

int		main(int ac, char **av)
{
	t_all	*gen;

	if (ac == 1)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putstr(" <sourcefile.s>\n");
		exit(-1);
	}
	gen = set_def_gen(av[ac - 1]);
	reading(gen);
	lexical_analyz(gen);
	check_constant(gen);
	recording(gen);
	do_free(gen);
	return (0);
}
