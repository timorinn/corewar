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

/*
*	Испольую Т_ИНД, тк размер Т_ДИР для этой операции равен 2.
*/

int		vm_op_zjmp(uint8_t map[MEM_SIZE][4], t_cursor *car)
{
	t_ind		ind;

	mvprintw(50, 200, "CARRy = %d", car->carry);
	if (!car->carry)
	{
		car->position = car->position + 3 > (MEM_SIZE - 1) ?
		car->position + 3 - MEM_SIZE : car->position + 3;
		return (1);
	}
	ft_init_t_ind(map, car->position + 1, &ind);
	car->position = car->position + ind.data % IDX_MOD > (MEM_SIZE - 1) ?
	car->position + ind.data % IDX_MOD - MEM_SIZE :
	car->position + ind.data % IDX_MOD;
	return (1);
}
