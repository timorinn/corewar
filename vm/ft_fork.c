/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:27:59 by bford             #+#    #+#             */
/*   Updated: 2019/12/19 16:13:48 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_fork(unsigned char map[MEM_SIZE][4], t_cursor *car, t_cursor **allcar)
{
	t_dir	dir;
	t_cursor	*newcar;
	int		size;

	if (!(newcar = (t_cursor *)malloc(sizeof(t_cursor) * (car[0].size + 1))))
		return (0);
	ft_init_t_dir(map, car->position + 1, &dir);
	size = car[0].size;
	while (--size >= 0)
		newcar[size + 1] = (*allcar)[size];
	newcar[0] = car[0];
	newcar[0].position = dir.data % MEM_SIZE; /* Что делать, если число отрицательное? */
}