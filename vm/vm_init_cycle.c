/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:28:34 by bford             #+#    #+#             */
/*   Updated: 2020/01/01 03:07:15 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_init_cycle(t_cycle *cycle, int player_size, t_flags flags, int v)
{
	cycle->v = v;
	cycle->cycle_num = 0;
//	cycle->new_cur_num = player_size;
	cycle->dump = flags.dump;
	cycle->log = flags.log;
	cycle->cur_len = player_size;
	cycle->lives_in_current_period_all = 0;
	cycle->checks = 0;
	cycle->cycles_to_die = CYCLE_TO_DIE;
	cycle->waiting_die = CYCLE_TO_DIE;
	ft_bzero(cycle->last_live, sizeof(int) * MAX_PLAYERS);
	ft_bzero(cycle->lives_in_current_period, sizeof(int) * MAX_PLAYERS);
	cycle->processes_qty = player_size;
}
