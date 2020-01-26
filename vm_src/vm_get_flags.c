/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:08:25 by kpsylock          #+#    #+#             */
/*   Updated: 2020/01/26 21:08:29 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static void		vm_check_ovewrflow_dump(char *argv, int dump)
{
	int		argv_len;
	int		nbr_len;

	argv_len = ft_strlen(argv);
	if (!argv_len || argv_len > 10 || dump < 0 ||
		(*argv == '0' && *(argv + 1) != '\0'))
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

inline static void		vm_init_dump(int argc, char **argv, t_flags *flags)
{
	if (argc > 2 && (!ft_strcmp(argv[1], "-dump")))
	{
		flags->dump = ft_atoi(argv[2]);
		vm_check_ovewrflow_dump(argv[2], flags->dump);
	}
	else
		flags->dump = -1;
}

inline static bool		get_log_flag(int ac, char **av, t_flags flags)
{
	int8_t offset;

	offset = flags.offset;
	return (ac > (offset + 1) && !ft_strcmp(av[offset + 1], "-log") ?
			true : false);
}

inline static bool		get_aff_flag(int ac, char **av, t_flags flags)
{
	uint8_t offset;

	offset = flags.offset;
	return (ac > (offset + 1) && !ft_strcmp(av[offset + 1], "-a") ?
			true : false);
}

void					vm_init_flags(int argc, char **argv, t_flags *flags)
{
	vm_init_dump(argc, argv, flags);
	flags->offset = (flags->dump == -1 ? 0 : 2);
	flags->log = get_log_flag(argc, argv, *flags);
	flags->offset += (flags->log == false ? 0 : 1);
	flags->aff = get_aff_flag(argc, argv, *flags);
	flags->offset += (flags->aff == false ? 0 : 1);
	flags->v = (!ft_strcmp(argv[argc - 1], "-v") ? true : false);
}
