/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:13:53 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:13:55 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

inline static int32_t	op_lfork(int32_t position, int32_t ind)
{
	return (position + ind >= 0 ?
	(position + ind) % MEM_SIZE :
	(position + ind) % MEM_SIZE + MEM_SIZE);
}

bool					vm_op_lfork(uint8_t map[MEM_SIZE][4],
		t_cursor **cur, t_cycle *cycle)
{
	if (cycle->log)
		vm_print_log_op("lfork", cycle);
	return (op_all_fork(map, cycle, cur, &op_lfork));
}
