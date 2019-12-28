/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:56:28 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 13:47:27 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	vm_op_add(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_args	args;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, cur, &args);
	if (vm_validate_args(args, "R--R--R--"))
	{
		cur->registr[args.nums[2]] = cur->registr[args.nums[0]] +
				cur->registr[args.nums[0]];
		if (cur->registr[args.nums[2]] == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
	}
	cur->position += ft_move(args.types, "1110", args.dir_size) + 2;
	cur->position %= MEM_SIZE;
	return (true);
}
