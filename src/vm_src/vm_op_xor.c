/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_xor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:35:25 by kpsylock          #+#    #+#             */
/*   Updated: 2020/01/25 13:34:50 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

inline static int32_t	op_xor(int32_t first, int32_t second)
{
	return (first ^ second);
}

bool					vm_op_xor(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	if (cycle->log)
		vm_print_log_op("xor", cycle);
	return (op_bitwise(map, &op_xor, cycle));
}
