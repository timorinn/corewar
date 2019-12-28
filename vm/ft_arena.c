/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:48:15 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 17:06:23 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_add_player(uint8_t map[MEM_SIZE + 1][4], t_player *player, int start)
{
	int				size;
	int				num;
	unsigned char	*code;
	int				i;

	i = 0;
	num = player->num;
	code = player->code;
	size = player->size;
	while (i < size && ++i)
	{
		map[start + i - 1][0] = code[i - 1];
		map[start + i - 1][1] = num + 2;
	}
	return (1);
}

t_player	*ft_find_player(int num, t_player *player)
{
	while (player->num != num)
		player = player->next;
	return (player);
}

int		ft_init_map(uint8_t map[MEM_SIZE][4], t_player *player)
{
	int		i;
	int		len;

	len = ft_lstlen_player(player);
	i = 0;
	while (i < MEM_SIZE + 1 && ++i)
	{
		map[i - 1][0] = 0;
		map[i - 1][1] = 1;
	}
	i = 0;
	while (i < len && ++i)
		ft_add_player(map, ft_find_player(i, player), (MEM_SIZE / len) * (i - 1));
	return (1);
}

int		ft_no_print_map(uint8_t map[MEM_SIZE][4], t_cursor **cur,
						t_player *player, t_cycle *cycle)
{
	ft_print_players(player);
	while (TRUE)
	{
		if (!(ft_do_cycle(map, cur, cycle)))
			return (0);
		if (cycle->dump == cycle->cycle_num)
		{
			ft_print_map_single(map);
			break;
		}
		cycle->cycle_num++;
	}
	return (1);
}

int		ft_arena(int dump, t_player *player, int v)
{
	unsigned char	map[MEM_SIZE][4];
	t_cursor		*cur;
	t_cycle			cycle;

	vm_init_cycle(&cycle, player->size, dump);
	ft_init_map(map, player);
	if (!player || !(cur = ft_make_array_cursor(player, map)))
		return (0);
	if (v)
		ft_print_map(map, &cur, player, &cycle);
	else
		ft_no_print_map(map, &cur, player, &cycle);
	free(cur);
	return (1);
}
