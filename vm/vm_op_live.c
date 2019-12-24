/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:54:32 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 22:01:59 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_op_live(uint8_t map[MEM_SIZE][4], t_cursor *car, int cycle)
{
	t_dir	dir;

	ft_init_t_dir(map, car->position + 1, &dir, 4);
	if (dir.data == car->play_num)
		car->live = cycle;
	car->position += 5;
	car->position %= MEM_SIZE;
	return (1);
}
