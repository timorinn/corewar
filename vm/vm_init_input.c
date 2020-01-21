/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:48:03 by bford             #+#    #+#             */
/*   Updated: 2019/12/06 19:17:58 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static void	vm_init_numbers(int8_t nums[MAX_PLAYERS])
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS && ++i)
		nums[i - 1] = 0;
}

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

t_player	*vm_init_input(int argc, char **argv, int8_t valid, t_flags flags)
{
	t_player	*player;
	int8_t		numbers[MAX_PLAYERS];
	int			i;

	i = 1;
	player = NULL;
	if (!valid)
		return (NULL);
	i += flags.offset;
	vm_init_numbers(numbers);
	argc -= (ft_strcmp(argv[argc - 1], "-v") ? 0 : 1);
	while (i < argc && ++i)
		if (!vm_init_player(argv, &i, &player, numbers))
			return (NULL + vm_lstdel_player(player));
	return (ft_make_player_num(player, numbers) ?
	player : NULL + vm_lstdel_player(player) + vm_error(4, 0));
}
