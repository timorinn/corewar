/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:56:28 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 13:47:27 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static int32_t	add(int32_t first, int32_t second)
{
	return (first + second);
}

bool					vm_op_add(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	if (cycle->log)
		vm_print_log_op("add", cycle);
	return (op_add_sub(map, &add, cycle));
}
