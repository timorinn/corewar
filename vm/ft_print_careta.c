/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_careta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:00:52 by bford             #+#    #+#             */
/*   Updated: 2019/12/11 14:09:06 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_print_careta(t_cursor *car)
{
	int	i;
	int	reg;

	i = 0;
	while (i < car->size)
	{
		printf("t_cursor pnum = %d | pos = %4d | op = %2d | cd = %3d | size = %d    || ",
		car[i].play_num, car[i].position, car[i].operation, car[i].cooldown, car[i].size);
		reg = 0;
		while (reg < 16 && ++reg)
			printf("r%d %d | ", reg, car[i].registr[reg - 1]);
		printf("\n");
		++i;
	}
	return (1);
}
