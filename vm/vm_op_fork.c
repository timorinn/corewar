/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:27:59 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 21:24:17 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static int32_t op_fork(int32_t position, int32_t ind)
{
	return (position + ind % IDX_MOD >= 0 ?
	(position + ind % IDX_MOD) % MEM_SIZE :
	(position + ind % IDX_MOD) + 4096);
}

bool	vm_op_fork(uint8_t map[MEM_SIZE][4], t_cursor *car,
t_cursor **allcar)
{
	return (vm_op_all_fork(map, car, allcar, &op_fork));
}
