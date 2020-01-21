//
// Created by Katharine Psylocke on 21/01/2020.
//

#include "vm.h"

inline static void	vm_print_winner(t_player *player, int winner_num)
{
	while (player->num != winner_num)
		player = player->next;
	ft_printf("Contestant %d, \"%s\", has won !\n", player->num, player->name);
}

void				vm_no_print_map(uint8_t map[MEM_SIZE][4], t_cursor **cur,
		t_player *player, t_cycle *cycle)
{
	vm_print_players(player);
	while (true)
	{
		if (cycle->log == true && cycle->cycle_num != 0)
			ft_printf("It is now cycle %d\n", cycle->cycle_num);
		vm_do_cycle(map, cur, cycle);
		if (vm_check_cursor(map, cur, cycle) == 1)
		{
			vm_print_winner(player, cycle->winner_num);
			break ;
		}
		if (cycle->dump == cycle->cycle_num)
		{
			vm_print_map_single(map);
			break ;
		}
		cycle->cycle_num++;
	}
}
