/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stasyan <stasyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 22:39:44 by bford             #+#    #+#             */
/*   Updated: 2019/12/17 10:45:06 by stasyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
*	Испольую Т_ИНД, тк размер Т_ДИР для этой операции равен 2.
*/

int		ft_zjmp(unsigned char map[4096][4], careta *car)
{
	t_ind		ind;

	mvprintw(50, 200, "CARRy = %d", car[0].carry);
	if (!car[0].carry)
	{
		car[0].position = car[0].position + 3 > 4095 ?
		car[0].position + 3 - 4096 : car[0].position + 3;
		return (1);
	}
	ft_init_t_ind(map, car[0].position + 1, &ind);
	car[0].position = car[0].position + ind.data % IDX_MOD > 4095 ?
	car[0].position + ind.data % IDX_MOD - 4096 :
	car[0].position + ind.data % IDX_MOD;
	return (1);
}
