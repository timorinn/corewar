/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_all_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:12:30 by bford             #+#    #+#             */
/*   Updated: 2019/12/24 18:24:04 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	vm_op_all_fork(uint8_t map[MEM_SIZE][4], t_cursor *car,
t_cursor **allcar, int32_t (*operation)(int32_t, int32_t))
{
	t_ind		ind;
	t_cursor	*newcar;
	int			size;

	size = car[0].size - 1;
	if (!(newcar = (t_cursor *)malloc(sizeof(t_cursor) * (size + 1))))
		return (FALSE);
	ft_init_t_ind(map, car->position + 1, &ind);
	while (size >= 0)
	{
		newcar[size + 1] = (*allcar)[size];
		if (newcar[size + 1].num == car->num)
			newcar[size + 1].position += 3;
		newcar[size + 1].size = car[0].size + 1;
		size--;
	}
	newcar[0] = *car;
	newcar[0].size = car->size + 1;
	newcar[0].num = car->size;
	/*
	newcar[0].position = (car->position + ind.data % IDX_MOD > 0 ?
	(car->position + ind.data % IDX_MOD) % MEM_SIZE :
	4096 + (car->position + ind.data % IDX_MOD));
	*/
	newcar[0].position = operation(car->position, ind.data);
	newcar[0].operation = map[newcar[0].position][0];
	newcar[0].cooldown = newcar[0].operation > 0 && newcar[0].operation < 17 ? 
	g_operation[newcar[0].operation] : 1;
	//free(*allcar);
	*allcar = newcar;
	return (TRUE);
}