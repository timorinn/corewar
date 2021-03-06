/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:06:56 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:07:06 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		vm_op_live(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_dir		dir;
	t_cursor	*cur;

	cur = cycle->now_cur;
	dir = vm_init_t_dir(map, cur->position + 1, 4);
	if (cycle->log)
	{
		vm_print_log_op("live", cycle);
		ft_printf(" %d\n", dir.data);
	}
	cur->live = cycle->cycle_num - 1;
	cycle->lives_in_current_period_all++;
	if (-dir.data > 0 && -dir.data <= MAX_PLAYERS)
	{
		cycle->lives_in_current_period[-dir.data]++;
		cycle->last_live[-dir.data] = cycle->cycle_num - 2;
		cycle->winner_num = -dir.data;
	}
	map[cur->position][2] -= 1;
	cur->position = (cur->position + 5) % MEM_SIZE;
	map[cur->position][2] += 1;
	cur->operation = -1;
	cur->cooldown = 0;
	return (1);
}
