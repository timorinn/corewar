/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 22:39:44 by bford             #+#    #+#             */
/*   Updated: 2019/12/14 22:56:38 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_zjmp(unsigned char map[4096][4], careta *car)
{
	t_dir			dir;

	mvprintw(50, 200, "CARRy = %d", car[0].carry);
	if (!car[0].carry)
	{
		car[0].position = car[0].position + 5 > 4095 ?
		car[0].position + 5 - 4096 : car[0].position + 5;
		return (1);
	}
	ft_init_t_dir(map, car[0].position + 1, &dir);
	car[0].position = car[0].position + dir.data % IDX_MOD > 4095 ?
	car[0].position + dir.data % IDX_MOD - 4096 :
	car[0].position + dir.data % IDX_MOD;
	return (1);
}
