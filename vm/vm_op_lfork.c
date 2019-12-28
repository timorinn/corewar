/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:07:59 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 21:24:08 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static int32_t op_lfork(int32_t position, int32_t ind)
{
	return (position + ind >= 0 ?
	(position + ind) % MEM_SIZE :
	(position + ind) + MEM_SIZE);
}

bool	vm_op_lfork(uint8_t map[MEM_SIZE][4], t_cursor **cur, t_cycle *cycle)
{
	return (vm_op_all_fork(map, cycle, cur, &op_lfork));
}
