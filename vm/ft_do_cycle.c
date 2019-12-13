/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:14:17 by bford             #+#    #+#             */
/*   Updated: 2019/12/13 18:31:52 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		g_operation[16] = {10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};


int		ft_do_operation(unsigned char map[4096][4], careta *car, int v)
{
	int		o;

	o = car[0].operation;

	if ( /* (o == 1 && ft_live(map, car)) || */ (o == 2 && ft_ld(map, car, v)) /* ||
	(o == 3 && ft_st(map, car)) || (o == 4 && ft_add(map, car)) ||
	(o == 5 && ft_sub(map, car)) || (o == 6 && ft_and(map, car)) ||
	(o == 7 && ft_or(map, car)) || (o == 8 && ft_xor(map, car)) ||
	(o == 9 && ft_zjmp(map, car)) || (o == 10 && ft_ldi(map, car)) ||
	(o == 11 && ft_sti(map, car)) || (o == 12 && ft_fork(map, car)) ||
	(o == 13 && ft_lld(map, car)) || (o == 14 && ft_lldi(map, car)) ||
	(o == 15 && ft_lfork(map, car)) || (o == 16 && ft_aff(map, car)) */ )
		return (1);
	car[0].position = car[0].position == 4095 ? 0 : car[0].position + 1;
	return (1);
	//car.operation == 1 ? ft_live(map, car) : 0;
	//car.operation == 2 ? ft_ld(map, car) : 0;
	//car.operation == 3 ? ft_st(map, car) : 0;
	//car.operation == 4 ? ft_add(map, car) : 0;
	//car.operation == 5 ? ft_sub(map, car) : 0;
	//car.operation == 6 ? ft_and(map, car) : 0;
	//car.operation == 7 ? ft_or(map, car) : 0;
	//car.operation == 8 ? ft_xor(map, car) : 0;
	//car.operation == 9 ? ft_zjmp(map, car) : 0;
	//car.operation == 10 ? ft_ldi(map, car) : 0;
	//car.operation == 11 ? ft_sti(map, car) : 0;
	//car.operation == 12 ? ft_fork(map, car) : 0;
	//car.operation == 13 ? ft_lld(map, car) : 0;
	//car.operation == 14 ? ft_lldi(map, car) : 0;
	//car.operation == 15 ? ft_lfork(map, car) : 0;
	//car.operation == 16 ? ft_aff(map, car) : 0;

}

int		ft_do_cycle(unsigned char map[4096][4], careta *car, int v)
{
	int		size;
	int		i;

	i = 0;
	size = (*car).size;
	while (i < size && ++i)
	{
		if (car[i - 1].operation == 666)
		{
			car[i - 1].operation = map[car[i - 1].position][0];
			car[i - 1].cooldown = g_operation[car[i - 1].operation];
			continue;
		}
		if (car[i - 1].cooldown == 0)
		{
			ft_do_operation(map, &car[i - 1], v);
		}
			//car[i - 1].cooldown = g_operation[car[i - 1].operation];
		else
			car[i - 1].cooldown--;
	}
	return (1);
}
