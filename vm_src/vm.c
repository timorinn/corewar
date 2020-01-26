/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:17:03 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 19:04:39 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_usage(int argc)
{
	if (argc == 1)
		exit(ft_putstr(
			"Usage: ./corewar [-dump N] \
[-log] [-a] [-n N] <champion1.cor> [-n N] <...> [-v]\n\
	-dump N		: Dumps memory after N cycles then exits\n\
	-log		: Show logs\n\
	-a			: aff operation output on\n\
	-n			: Assign a number N to the champion\n\
	-v			: Ncurses output mode\n"));
}

int			main(int argc, char **argv)
{
	t_player	*player;
	t_flags		flags;

	player = NULL;
	vm_usage(argc);
	vm_init_flags(argc, argv, &flags);
	player = vm_init_input(argc, argv, flags);
	vm_arena(flags, player);
	return (vm_lstdel_player(player));
}
