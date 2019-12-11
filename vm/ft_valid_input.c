/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:53:12 by bford             #+#    #+#             */
/*   Updated: 2019/12/09 17:25:56 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_check_name_player(const char *name)
{
	while (*name && *name != '.')
		name++;
	return (*name && !ft_strcmp(name, ".cor") ? 1 : 0);
}

static void	ft_init_numbers(int *nums)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS && ++i)
		nums[i - 1] = 0;
}

static int	ft_valid_argv(int argc, char **argv, int *i, int *players)
{
	if (!ft_strcmp(argv[*i - 1], "-n"))
	{
		/* НЕ УДАЛЯТЬ!
		return (argc >= *i + 2 && ft_isint(argv[*i], 1, 0, 1) &&
		ft_atoi(argv[*i]) > 0 && ft_atoi(argv[*i]) <= MAX_PLAYERS &&
		players[ft_atoi(argv[*i]) - 1] == 0 &&
		(players[ft_atoi(argv[*i]) - 1] += 1) &&
		ft_check_name_player(argv[*i + 1]) && (*i += 2) ? 1 : 0);
		*/
		if (argc < *i + 2)
			return (ft_putstr_fd("Error: -n: not enough arguments\n", 2));
		else if (!ft_isint(argv[*i], 1, 0, 1) || ft_atoi(argv[*i]) < 1 ||
		ft_atoi(argv[*i]) > MAX_PLAYERS)
			return (ft_putstr_fd("Error: -n: invalid player number\n", 2));
		else if (players[ft_atoi(argv[*i]) - 1] != 0)
			return (ft_putstr_fd("Error: -n: repeat player number\n", 2));
		else if (!ft_check_name_player(argv[*i + 1]))
			return (ft_error(1, argv[*i - 1]));
		return ((players[ft_atoi(argv[*i]) - 1] += 1) && (*i += 2));
	}
	return (ft_check_name_player(argv[*i - 1]) ? 1 :
	ft_error(1, argv[*i - 1]));
}

static int	ft_valid_dump(int argc, char **argv, int *i)
{
	if (!ft_strcmp(argv[1], "-dump"))
	{
		//return (argc >= 4 && ft_isint(argv[2], 1, 0, 1) && (*i += 2) ? 1 : 0);
		if (argc < 4)
			return (ft_putstr("Error: not enough arguments\n"));
		else if (!ft_isint(argv[2], 1, 0, 1))
			return (ft_putstr("Error: -dump: wrong number of cycles\n"));
		else
			return ((*i += 2));
	}
	return (1);
}

int			ft_valid_input(int argc, char **argv)
{
	int		i;
	int		players_num;
	int		nums[MAX_PLAYERS];

	i = 1;
	players_num = 0;
	ft_init_numbers(nums);
	if (argc < 2 || !ft_valid_dump(argc, argv, &i))
		return (0);
	argc -= (ft_strcmp(argv[argc - 1], "-v") ? 0 : 1);
	while (i < argc && ++i)
	{
		if (!ft_valid_argv(argc, argv, &i, nums))
			return (0);
		if (++players_num > MAX_PLAYERS)
			return (ft_error(7, 0));
	}
	return (1);
}
