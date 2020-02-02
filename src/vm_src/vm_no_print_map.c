/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_no_print_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:21:45 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 16:07:48 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	vm_print_winner(t_player *player, int winner_num)
{
	while (player->next && player->num != winner_num)
		player = player->next;
	ft_printf("Contestant %d, \"%s\", has won !\n", player->num, player->name);
}

static void	print_map_single(uint8_t map[MEM_SIZE][4])
{
	int		i;

	i = 1;
	while (i < MEM_SIZE + 1)
	{
		if (i % DUMP_WIDTH == 1)
			ft_printf("0x%03x0 : ", i / 16);
		ft_printf("%02x ", map[i - 1][0]);
		if (i % DUMP_WIDTH == 0)
			ft_printf("\n");
		i++;
	}
}

void				vm_no_print_map(uint8_t map[MEM_SIZE][4], t_cursor **cur,
		t_player *player, t_cycle *cycle)
{
	vm_print_players(player);
	while (true)
	{
		if (cycle->log == true)
			ft_printf("It is now cycle %d\n", cycle->cycle_num);
		vm_do_cycle(map, cur, cycle);
		if (vm_check_cursor(map, cur, cycle) == 1)
		{
			vm_print_winner(player, cycle->winner_num);
			break ;
		}
		if (cycle->dump == cycle->cycle_num)
		{
			print_map_single(map);
			break ;
		}
		cycle->cycle_num++;
	}
}
