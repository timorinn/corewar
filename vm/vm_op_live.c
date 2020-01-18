/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:54:32 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 22:01:59 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_op_live(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_dir		dir;
	t_cursor	*cur;

	cur = cycle->now_cur;
	dir = ft_init_t_dir(map, cur->position + 1, 4);

	if (cycle->log)
	{
		vm_print_log_op("live", cycle);
		printf(" %d\n", dir.data);
	}

	cur->live = cycle->cycle_num - 1;
	cycle->lives_in_current_period_all++;

	// if (dir.data == -1 * cur->play_num)
	if (-dir.data > 0 && -dir.data <= MAX_PLAYERS)
	{

		////cycle->lives_in_current_period[cur->play_num]++;
		cycle->lives_in_current_period[-dir.data]++;

		////cycle->last_live[cur->play_num] = cycle->cycle_num - 1; 
		cycle->last_live[-dir.data] = cycle->cycle_num - 1; 

		////cycle->winner_num = cur->play_num;
		cycle->winner_num = -dir.data;
	}
	map[cur->position][2] -= 1;
	cur->position = (cur->position + 5) % MEM_SIZE;
	map[cur->position][2] += 1;

	cur->operation = -1;
	cur->cooldown = 0;

	//
	// if (cycle->log == true)
	// 	ft_putendl(" It could be live args here, but there is this text.");
	//
	return (1);
}
