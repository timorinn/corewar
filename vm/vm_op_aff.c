/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:55:55 by bford             #+#    #+#             */
/*   Updated: 2020/01/05 17:16:28 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	vm_op_aff(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	uint8_t	args[4];
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_init_args(map, cur->position, args);

	// if (args[0] == 1 && !args[1] && !args[2] &&						ARGS ERROR commit
	if (args[0] == 1 && !args[1] && !args[2] &&

	map[cur->position + 2][0] >= 1 &&
	map[cur->position + 2][0] <= 16)
	{
		if (cycle->v)
		{
			mvprintw(67, 253, "Aff: %c", (char)(cur->registr[map[cur->position + 2][0]]));
			refresh();
		}
		else
		{
			ft_putstr("Aff: ");
			ft_putchar(cur->registr[map[cur->position + 2][0]]);
			ft_putchar('\n');
		}
	}

	// cur->position += ft_move(args, "1110", 4) + 2;					ARGS ERROR commit
	/*
	cur->position += ft_move(args, "1000", 4) + 2;
	cur->position %= MEM_SIZE;
	*/
	map[cur->position][2] -= 1;
	ft_move(cur, args, "1000", 4);
	map[cur->position][2] += 1;
	return (true);
}
