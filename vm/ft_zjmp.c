/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
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

int		ft_zjmp(unsigned char map[4096][4], careta *car)
{
	t_ind		ind;

	mvprintw(50, 200, "CARRy = %d", car->carry);
	if (!car->carry)
	{
		car->position = car->position + 3 > 4095 ?
		car->position + 3 - 4096 : car->position + 3;
		return (1);
	}
	ft_init_t_ind(map, car->position + 1, &ind);
	car->position = car->position + ind.data % IDX_MOD > 4095 ?
	car->position + ind.data % IDX_MOD - 4096 :
	car->position + ind.data % IDX_MOD;
	return (1);
}
