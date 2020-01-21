/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:01:47 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 14:01:48 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
/*
bool	vm_op_sub(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_args		args;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, cur, &args);
	if (vm_validate_args(args, "R--R--R--"))
	{
		cur->registr[args.nums[2]] = cur->registr[args.nums[0]] +
									 cur->registr[args.nums[0]];

// ^^^ And here is the fuckup again! Now fixed <3

		if (cur->registr[args.nums[2]] == 0)
			cur->carry = 1;
		else
			cur->carry = 0;
	}
	cur->position += vm_move(args.types, "1110", args.dir_size) + 2;
	cur->position %= MEM_SIZE;
	return (true);
}
*/

inline static int32_t	sub(int32_t first, int32_t second)
{
	return (first - second);
}

bool					vm_op_sub(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	if (cycle->log)
		vm_print_log_op("sub", cycle);
	return (op_add_sub(map, &sub, cycle));
}