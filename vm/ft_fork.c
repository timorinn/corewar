/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:27:59 by bford             #+#    #+#             */
/*   Updated: 2019/12/19 19:31:09 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_fork(unsigned char map[MEM_SIZE][4], t_cursor *car, t_cursor **allcar)
{
	t_ind		ind;
	t_cursor	*newcar;
	int			size;

	if (!(newcar = (t_cursor *)malloc(sizeof(t_cursor) * (car[0].size + 1))))
		return (0);
		
	ft_init_t_ind(map, car->position + 1, &ind);
	size = car[0].size;
	while (--size >= 0)
	{
		newcar[size + 1] = (*allcar)[size];
		newcar[size + 1].size = car[0].size + 1;
	}
	newcar[0] = car[0];
	newcar[0].num = car[0].size;
	newcar[0].position = ind.data % MEM_SIZE; /* Что делать, если число отрицательное? */
	return (1);
}