/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 21:35:25 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 14:41:28 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static int32_t op_and(int32_t first, int32_t second)
{
	return (first & second);
}

bool	vm_op_and(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	return (op_bitwise(map, &op_and, cycle));
}
