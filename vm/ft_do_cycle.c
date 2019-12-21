/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:14:17 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 21:27:29 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_do_operation(unsigned char map[MEM_SIZE][4],
						t_cursor *car, t_cursor **allcar, int cycle)
{
	int		o;

	o = car->operation;

	if ( (o == 1 && ft_live(map, car, cycle)) || (o == 2 && ft_ld(map, car)) ||
	(o == 3 && ft_st(map, car)) ||  (o == 4 && ft_add(map, car)) ||
	(o == 5 && ft_sub(map, car)) || (o == 6 && ft_and(map, car)) || /*
	(o == 7 && ft_or(map, car)) || (o == 8 && ft_xor(map, car)) || */
	(o == 9 && ft_zjmp(map, car)) /* || (o == 10 && ft_ldi(map, car)) ||
	(o == 11 && ft_sti(map, car)) */ || (o == 13 && ft_lld(map, car)) /*||
	(o == 14 && ft_lldi(map, car)) || (o == 16 && ft_aff(map, car))*/)
		return (0);
	else if ((o == 12) || (o == 15))
	{
		if (o == 12)
			return (ft_fork(map, car, allcar));
		return (ft_lfork(map, car, allcar));
	}
	car->position = (car->position == (MEM_SIZE - 1) ? 0 : car->position + 1);
	//mvprintw(85 + 1, 16, "FREE PLACE! Car_position = %d", car->position);
	return (0);
}

int		ft_do_cycle(unsigned char map[MEM_SIZE][4], t_cursor **car, int cycle)
{
	int		i;

	i = 0;
	while (i < (*car)->size)
	{
		if ((*car)[i].cooldown == 0)
		{
			i += ft_do_operation(map, &(*car)[i], car);
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
