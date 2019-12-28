/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:35:25 by kpsylock          #+#    #+#             */
/*   Updated: 2019/12/28 13:51:59 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static int32_t op_or(int32_t first, int32_t second)
{
	return (first | second);
}

bool	vm_op_or(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	return (op_bitwise(map, &op_or, cycle));
}