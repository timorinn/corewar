/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:48:03 by bford             #+#    #+#             */
/*   Updated: 2020/01/22 15:23:53 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int8_t		ft_make_player_num(t_player *player,
		const int8_t numbers[MAX_PLAYERS])
{
	int8_t	i;
	int8_t	len;

	i = 0;
	len = vm_lstlen_player(player);
	while (player)
	{
		if (player->num == 0)
		{
			while (numbers[i])
				i++;
			player->num = ++i;
		}
		if (player->num > len)
			return (0);
		player = player->next;
	}
	return (1);
}

t_player	*vm_init_input(int argc, char **argv, t_flags flags)
{
	t_player	*player;
	int8_t		numbers[MAX_PLAYERS];
	int			i;

	i = 1;
	player = NULL;
	vm_valid_input(argc, argv, flags);
	i += flags.offset;
	ft_bzero(numbers, sizeof(int8_t) * MAX_PLAYERS);
	argc -= (ft_strcmp(argv[argc - 1], "-v") ? 0 : 1);
	while (i < argc && ++i)
		vm_init_player(argv, &i, &player, numbers);
	return (ft_make_player_num(player, numbers) ?
	player : NULL + vm_lstdel_player(player) + vm_error(4, 0));
}
