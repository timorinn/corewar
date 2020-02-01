/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:55:55 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:21:22 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

bool	vm_op_aff(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	uint8_t		args[4];
	t_cursor	*cur;

	cur = cycle->now_cur;
	vm_init_args(map, cur->position, args);
	if (cycle->aff == true && args[0] == 1 && !args[1] && !args[2] &&
	map[cur->position + 2][0] >= 1 &&
	map[cur->position + 2][0] <= 16)
	{
		if (cycle->v)
		{
			mvprintw(67, 253, "Aff: %c",
					(char)(cur->registr[map[cur->position + 2][0]]));
			refresh();
		}
		else
			ft_printf("Aff: %c\n", cur->registr[map[cur->position + 2][0]]);
	}
	map[cur->position][2] -= 1;
	vm_move(cur, args, "1000", 4);
	map[cur->position][2] += 1;
	return (true);
}
