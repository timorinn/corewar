/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:18:28 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:18:45 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static int32_t	op_fork(int32_t position, int32_t ind)
{
	return (position + ind % IDX_MOD >= 0 ?
	(position + ind % IDX_MOD) % MEM_SIZE :
	(position + ind % IDX_MOD) % MEM_SIZE + MEM_SIZE);
}

bool					vm_op_fork(uint8_t map[MEM_SIZE][4],
		t_cursor **cur, t_cycle *cycle)
{
	if (cycle->log)
		vm_print_log_op("fork", cycle);
	return (op_all_fork(map, cycle, cur, &op_fork));
}
