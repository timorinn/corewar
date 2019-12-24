/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:55:55 by bford             #+#    #+#             */
/*   Updated: 2019/12/24 17:12:38 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	vm_op_aff(uint8_t map[MEM_SIZE][4], t_cursor *car)
{
	uint8_t	args[4];

	ft_init_args(map, car->position, args);
	if (args[0] == 1 && !args[1] && !args[2] &&
	map[car->position + 2][0] >= 1 &&
	map[car->position + 2][0] <= 16)
	{
		mvprintw(67, 253, "Aff: %c", (char)(car->registr[map[car->position + 2][0]]));
		refresh();
	}
	car->position += ft_move(args, "1110", 4) + 2;
	car->position %= MEM_SIZE;
	return (TRUE);
}
