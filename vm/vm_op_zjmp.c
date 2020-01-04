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

/*
	mvprintw(50, 200, "CARRy = %d", cur->carry);
	map[cur->position][2] = 0;
	if (!cur->carry)
	{
		//		//cur->position = cur->position + 3 > (MEM_SIZE - 1) ?
		//		//cur->position + 3 - MEM_SIZE : cur->position + 3;
		cur->position = (cur->position + 3) % MEM_SIZE;
		map[cur->position][2] = 1;
		return (1);
	}
	//		//cur->position = cur->position + ind.data % IDX_MOD > (MEM_SIZE - 1) ?
	//		//cur->position + ind.data % IDX_MOD - MEM_SIZE :
	//		//cur->position + ind.data % IDX_MOD;
	// cur->position += ind.data % IDX_MOD;
	// cur->position %= MEM_SIZE;
	ft_init_t_ind(map, cur->position + 1, &ind);
	cur->position = (cur->position + ind.data % IDX_MOD) % MEM_SIZE;
	map[cur->position][2] = 1;
*/

	map[cur->position][2] = 0;
	ft_init_t_ind(map, cur->position + 1, &ind);
	cur->position = (cur->position +
		(cur->carry ? ind.data % IDX_MOD : 3)) % MEM_SIZE;
	map[cur->position][2] = 1;
	return (1);
}
