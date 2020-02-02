/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:53:12 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 12:45:44 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	check_name_player(const char *name)
{
	uint32_t	len;

	if (name != NULL)
		len = ft_strlen(name);
	else
		len = 0;
	if (len >= 4 && !ft_strcmp(&(name[len - 4]), ".cor"))
		return ;
	exit(vm_error(1, name));
}

static void	valid_argv(int argc, char **argv, int *i, int8_t *players)
{
	int		player_num;

	if (!ft_strcmp(argv[*i], "-n"))
	{
		if (argc < *i + 2)
			exit(vm_error(3, 0));
		player_num = ft_atoi(argv[*i + 1]);
		if (!ft_isint(argv[*i + 1], 1, 1, 1) || player_num < 1 ||
		player_num > MAX_PLAYERS)
			exit(vm_error(10, 0));
		else if (players[player_num - 1] != 0)
			exit(vm_error(11, 0));
		check_name_player(argv[*i + 2]);
		players[player_num - 1] += 1;
		*i += 2;
	}
	check_name_player(argv[*i]);
}

inline void			vm_valid_input(int argc, char **argv, t_flags flags)
{
	int		i;
	int		players_count;
	int8_t	nums[MAX_PLAYERS];

	i = 1;
	players_count = 0;
	ft_bzero(nums, sizeof(int8_t) * MAX_PLAYERS);
	i += (flags.dump != -1 ? 2 : 0) + (flags.log ? 1 : 0) + (flags.aff ? 1 : 0);
	if (flags.v && flags.log)
		exit(vm_error(13, 0));
	argc -= (ft_strcmp(argv[argc - 1], "-v") ? 0 : 1);
	while (i < argc)
	{
		valid_argv(argc, argv, &i, nums);
		if (++players_count > MAX_PLAYERS)
			exit(vm_error(7, 0));
		i++;
	}
}
