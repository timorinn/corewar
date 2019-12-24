/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:14:17 by bford             #+#    #+#             */
/*   Updated: 2019/12/24 16:11:38 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_do_operation(uint8_t map[MEM_SIZE][4],
						t_cursor *car, t_cursor **allcar, int cycle)
{
	int		o;

	o = car->operation;
	if ((o == 1 && vm_op_live(map, car, cycle)) ||
	(o == 2 && vm_op_ld(map, car)) || (o == 3 && vm_op_st(map, car)) ||
	(o == 4 && vm_op_add(map, car)) || (o == 5 && vm_op_sub(map, car)) ||
	(o == 6 && vm_op_and(map, car)) || (o == 7 && vm_op_or(map, car)) ||
	(o == 8 && vm_op_xor(map, car)) || (o == 9 && vm_op_zjmp(map, car)) ||
	(o == 10 && vm_op_ldi(map, car)) || (o == 11 && vm_op_sti(map, car)) ||
	(o == 13 && vm_op_lld(map, car)) || (o == 14 && vm_op_lldi(map, car)) ||
	(o == 16 && vm_op_aff(map, car)))
		return (0);
	else if ((o == 12) || (o == 15))
	{
		if (o == 12)
			return (vm_op_fork(map, car, allcar));
		return (vm_op_lfork(map, car, allcar));
	}
	car->position = (car->position == (MEM_SIZE - 1) ? 0 : car->position + 1);
	//mvprintw(85 + 1, 16, "FREE PLACE! Car_position = %d", car->position);
	return (0);
}

int		ft_do_cycle(uint8_t map[MEM_SIZE][4], t_cursor **car, int cycle)
{
	int		i;

	i = 0;
	while (i < (*car)->size)
	{
		if ((*car)[i].cooldown == 0)
		{
			i += ft_do_operation(map, &(*car)[i], car, cycle);
			if (map[(*car)[i].position][0] > 0 && map[(*car)[i].position][0] < 17)
				(*car)[i].cooldown = g_operation[map[(*car)[i].position][0] - 1];
			(*car)[i].operation = map[(*car)[i].position][0];
		}
		else
			(*car)[i].cooldown--;
		i++;
	}
	return (1);
}
