/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:17:03 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 17:31:28 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_check_ovewrflow_dump(char *argv, int dump)
{
	int		argv_len;
	int		nbr_len;

	argv_len = ft_strlen(argv);
	if (!argv_len || argv_len > 10 || dump < 0)
		exit(vm_error(6, 0));
	while (*argv)
		if (!ft_isdigit(*argv++))
			exit(vm_error(6, 0));
	if (dump == 0)
		return ;
	nbr_len = 0;
	while (dump)
	{
		dump /= 10;
		nbr_len++;
	}
	if (nbr_len != argv_len)
		exit(vm_error(6, 0));
}

void		vm_init_dump(int argc, char **argv, t_flags *flags)
{
	if (argc > 2 && (!ft_strcmp(argv[1], "-dump")))
	{
		flags->dump = ft_atoi(argv[2]);
		vm_check_ovewrflow_dump(argv[2], flags->dump);
	}
	else
		flags->dump = -1;
}

bool		vm_get_log_flag(int ac, char **av, t_flags flags)
{
	int8_t offset;

	offset = flags.offset;
	return (ac > (offset + 1) && !ft_strcmp(av[offset + 1], "-log") ?
	true : false);
}

void		vm_init_flags(int argc, char **argv, t_flags *flags)
{
	vm_init_dump(argc, argv, flags);
	flags->offset = (flags->dump == -1 ? 0 : 2);
	flags->log = vm_get_log_flag(argc, argv, *flags);
	flags->offset += (flags->log == false ? 0 : 1);
	flags->v = (!ft_strcmp(argv[argc - 1], "-v") ? true : false);
}

void		vm_usage(int argc)
{
	if (argc == 1)
		exit(ft_putstr(
			"Usage: ./corewar [-dump N] \
[-log] [-n N] <champion1.cor> [-n N] <...> [-v]\n\
	-dump N		: Dumps memory after N cycles then exits\n\
	-log		: Show logs\n\
	-n		: Assign a number N to the champion\n\
	-v		: Ncurses output mode\n"));
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
