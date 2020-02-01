/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:02:01 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 14:02:03 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

bool	vm_op_lldi(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	if (cycle->log)
		vm_print_log_op("lldi", cycle);
	return (op_load_i(map, true, cycle));
}
