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

int		vm_op_live(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_dir		dir;
	t_cursor	*cur;

	cur = cycle->now_cur;
	dir = ft_init_t_dir(map, cur->position + 1, 4);
	if (dir.data == -cur->play_num)
		cur->live = cycle->cycle_num - 1;
	cur->position += 5;
	cur->position %= MEM_SIZE;
	return (1);
}
