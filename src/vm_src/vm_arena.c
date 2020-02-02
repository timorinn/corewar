/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:48:15 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 17:31:00 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		add_player(uint8_t map[MEM_SIZE][4], t_player *player,
		int16_t start)
{
	int32_t			size;
	int8_t			num;
	unsigned char	*code;
	int32_t			i;

	num = player->num;
	code = player->code;
	size = player->size;
	map[start][2] = 1;
	i = 0;
	while (i < size)
	{
		map[start + i][0] = code[i];
		map[start + i][1] = num;
		i++;
	}
}

static t_player	*find_player(int num, t_player *player)
{
	while (player->num != num)
		player = player->next;
	return (player);
}

static void		init_map(uint8_t map[MEM_SIZE][4], t_player *player)
{
	int16_t	i;
	int16_t	len;

	len = vm_lstlen_player(player);
	i = 0;
	while (i < MEM_SIZE + 1)
	{
		map[i][0] = 0;
		map[i][1] = 5;
		map[i][2] = 0;
		i++;
	}
	i = 0;
	while (i < len && ++i)
		add_player(map, find_player(i, player), (MEM_SIZE / len) * (i - 1));
}

void					vm_arena(t_flags flags, t_player *player)
{
	unsigned char	map[MEM_SIZE][4];
	t_cursor		*cur;
	t_cycle			cycle;
	int8_t			player_qty;

	player_qty = vm_lstlen_player(player);
	vm_init_cycle(&cycle, player_qty, flags);
	init_map(map, player);
	if (!player || !(cur = vm_make_start_list_cursor(player, map)))
		exit(vm_error(10, 0));
	if (cycle.v)
		vm_print_map(map, &cur, player, &cycle);
	else
		vm_no_print_map(map, &cur, player, &cycle);
	vm_lstdel_cursor(cur);
}
