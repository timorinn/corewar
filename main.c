/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:17:03 by bford             #+#    #+#             */
/*   Updated: 2020/01/20 17:58:23 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

int8_t		ft_visu(int argc, char **argv)
{
	return (!ft_strcmp(argv[argc - 1], "-v"));
}

int			ft_init_dump(int argc, char **argv)
{

	return (argc > 1 && !ft_strcmp(argv[1], "-dump") && ft_isint(argv[2], 1, 1, 1) ? ft_atoi(argv[2]) : -1);
}

bool		vm_get_log_flag(int ac, char **av, t_flags flags)
{
	int8_t offset;

	offset = flags.offset;
	return (ac > (offset + 1) && !ft_strcmp(av[offset + 1], "-log") ? true : false);
}

int			main(int argc, char **argv)
{
	t_player	*player;
	t_flags		flags;

	player = NULL;
	flags.dump = ft_init_dump(argc, argv);
	flags.offset = (flags.dump == -1 ? 0 : 2);
	flags.log = vm_get_log_flag(argc, argv, flags);
	flags.offset += (flags.log == false ? 0 : 1);
	player = vm_init_input(argc, argv, vm_valid_input(argc, argv), flags);
	/* СЕГА ПРИ ОГРОМНОМ ЗНАЧЕНИИ ДАМПА! */
	vm_arena(flags, player, ft_visu(argc, argv));

	//ft_print_player_param(player, 0);

	return (vm_lstdel_player(player));
}
