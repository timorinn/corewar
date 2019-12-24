/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:56:28 by bford             #+#    #+#             */
/*   Updated: 2019/12/24 15:56:30 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	vm_op_add(uint8_t map[MEM_SIZE][4], t_cursor *car)
{
	t_args	args;

	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, car, &args);
	if (vm_validate_args(args, "R--R--R--"))
	{
		car->registr[args.nums[2]] = car->registr[args.nums[0]] +
				car->registr[args.nums[0]];
		if (car->registr[args.nums[2]] == 0)
			car->carry = 1;
		else
			car->carry = 0;
	}
	car->position += ft_move(args.types, "1110", args.dir_size) + 2;
	car->position %= MEM_SIZE;
	return (true);
}
