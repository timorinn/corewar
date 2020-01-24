/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:00:53 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:00:54 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_op_zjmp(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_ind		ind;
	t_cursor	*cur;

	cur = cycle->now_cur;
	map[cur->position][2] -= 1;
	vm_init_t_ind(map, cur->position + 1, &ind);
	if (cycle->log)
	{
		vm_print_log_op("zjmp", cycle);
		ft_printf(" %d ", ind.data);
		cur->carry ? ft_printf("OK\n") : ft_printf("FAILED\n");
	}
	cur->position += (cur->carry ? (ind.data % IDX_MOD) : 3);
	cur->position %= MEM_SIZE;
	if (cur->position < 0)
		cur->position += MEM_SIZE;
	cur->operation = -1;
	cur->cooldown = 0;
	map[cur->position][2] += 1;
	return (1);
}
