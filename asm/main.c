/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swedde <swedde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:48:57 by swedde            #+#    #+#             */
/*   Updated: 2020/01/23 03:10:50 by swedde           ###   ########.fr       */
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
	recording(gen);
	do_free(gen);
	return (0);
}
