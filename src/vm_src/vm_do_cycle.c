/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_do_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:14:17 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 13:35:19 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		ft_do_operation(uint8_t map[MEM_SIZE][4],
						t_cursor **cur, t_cycle *cycle)
{
	int		o;

	o = cycle->now_cur->operation;
	if ((o == 1 && vm_op_live(map, cycle)) ||
	(o == 2 && vm_op_ld(map, cycle)) || (o == 3 && vm_op_st(map, cycle)) ||
	(o == 4 && vm_op_add(map, cycle)) || (o == 5 && vm_op_sub(map, cycle)) ||
	(o == 6 && vm_op_and(map, cycle)) || (o == 7 && vm_op_or(map, cycle)) ||
	(o == 8 && vm_op_xor(map, cycle)) || (o == 9 && vm_op_zjmp(map, cycle)) ||
	(o == 10 && vm_op_ldi(map, cycle)) || (o == 11 && vm_op_sti(map, cycle)) ||
	(o == 13 && vm_op_lld(map, cycle)) ||
	(o == 14 && vm_op_lldi(map, cycle)) ||
	(o == 16 && vm_op_aff(map, cycle)))
		return (1);
	else if (o == 12)
		return (vm_op_fork(map, cur, cycle));
	else if (o == 15)
		return (vm_op_lfork(map, cur, cycle));
	map[cycle->now_cur->position][2] -= 1;
	cycle->now_cur->position = (cycle->now_cur->position + 1) % MEM_SIZE;
	map[cycle->now_cur->position][2] += 1;
	return (1);
}

int		vm_do_cycle(uint8_t map[MEM_SIZE][4], t_cursor **cur, t_cycle *cycle)
{
	t_cursor	*copy;

	copy = *cur;
	while (copy)
	{
		if (copy->operation == -1 &&
		map[copy->position][0] > 0 && map[copy->position][0] < 17)
		{
			copy->cooldown = g_operation[map[copy->position][0] - 1] - 1;
			copy->operation = map[copy->position][0];
		}
		if (copy->cooldown == 0)
		{
			cycle->now_cur = copy;
			ft_do_operation(map, cur, cycle);
			cycle->now_cur->operation = -1;
			cycle->now_cur->cooldown = 0;
		}
		else
			copy->cooldown--;
		copy = copy->next;
	}
	return (1);
}
