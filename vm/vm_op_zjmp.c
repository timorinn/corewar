/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 22:39:44 by bford             #+#    #+#             */
/*   Updated: 2019/12/19 16:15:33 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_op_zjmp(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_ind		ind;
	t_cursor	*cur;

	cur = cycle->now_cur;
	mvprintw(50, 200, "CARRy = %d", cur->carry);
	if (!cur->carry)
	{
		cur->position = cur->position + 3 > (MEM_SIZE - 1) ?
		cur->position + 3 - MEM_SIZE : cur->position + 3;
		return (1);
	}
	ft_init_t_ind(map, cur->position + 1, &ind);
	cur->position = cur->position + ind.data % IDX_MOD > (MEM_SIZE - 1) ?
	cur->position + ind.data % IDX_MOD - MEM_SIZE :
	cur->position + ind.data % IDX_MOD;
	return (1);
}
