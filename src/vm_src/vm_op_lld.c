/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:16:43 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:16:47 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

bool	vm_op_lld(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	if (cycle->log)
		vm_print_log_op("lld", cycle);
	return (op_load(map, false, cycle));
}
