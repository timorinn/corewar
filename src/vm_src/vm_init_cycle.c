/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:28:34 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 16:06:00 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	vm_init_cycle(t_cycle *cycle, int player_size, t_flags flags)
{
	cycle->v = flags.v;
	cycle->cycle_num = 0;
	cycle->dump = flags.dump;
	cycle->log = flags.log;
	cycle->aff = flags.aff;
	cycle->cur_len = player_size;
	cycle->lives_in_current_period_all = 0;
	cycle->checks = 0;
	cycle->cycles_to_die = CYCLE_TO_DIE;
	cycle->waiting_die = CYCLE_TO_DIE;
	ft_bzero(cycle->last_live, sizeof(int) * MAX_PLAYERS);
	ft_bzero(cycle->lives_in_current_period, sizeof(int) * MAX_PLAYERS);
	cycle->processes_qty = player_size;
}
