/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:48:03 by bford             #+#    #+#             */
/*   Updated: 2019/12/05 14:27:38 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_init_numbers(int *nums)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS && ++i)
		nums[i - 1] = 0;
}

static int	ft_init_dump(int argc, char **argv, int *i)
{
	return (argc > 1 && !ft_strcmp(argv[1], "-dump") && (*i += 2) ?
	ft_atoi(argv[2]) : -1);
}



t_player	*ft_init_input(int argc, char **argv, int valid)
{
	t_player	*player;
	int			numbers[MAX_PLAYERS];
	int			cycle;
	int			i;

	i = 1;
	player = NULL;
	if (!valid)
		return (NULL);
	cycle = ft_init_dump(argc, argv, &i);
	ft_init_numbers(numbers);
	while (i < argc && ++i)
	{
		//printf("argv[%d] = %s\n", i - 1, argv[i - 1]);

		if (!ft_init_player(argv, &i, &player, numbers))
			return (NULL + ft_lstdel_player(player));
	}
	return (player);
}
