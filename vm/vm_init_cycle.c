/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:28:34 by bford             #+#    #+#             */
/*   Updated: 2019/12/29 04:35:58 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_init_cycle(t_cycle *cycle, int player_size, int dump)
{
	cycle->cycle_num = 0;
	cycle->new_cur_num = player_size;
	cycle->dump = dump;
	cycle->cur_len = player_size;
	cycle->last_period_live = 0;
}
