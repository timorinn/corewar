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

	cur->live = cycle->cycle_num - 1;
	cycle->lives_in_current_period_all++;

	if (dir.data == -1 * cur->play_num)
	{
		// cur->live = cycle->cycle_num - 1;
		cycle->lives_in_current_period[cur->play_num]++;
		// cycle->lives_in_current_period_all++;
		cycle->last_live[cur->play_num] = cycle->cycle_num - 1; 
		cycle->winner_num = cur->play_num;
	}
	map[cur->position][2] = 0;
	cur->position = (cur->position + 5) % MEM_SIZE;
	map[cur->position][2] = 1;
	return (1);
}
