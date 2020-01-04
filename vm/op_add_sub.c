/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 17:53:10 by bford             #+#    #+#             */
/*   Updated: 2020/01/04 13:17:27 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline bool	op_add_sub(uint8_t map[MEM_SIZE][4],
				   int32_t (*operation)(int32_t, int32_t), t_cycle *cycle)
{
	t_args		args;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, cur, &args);

	// if (vm_validate_args(args, "R--R--R--"))								ARGS ERROR commit
	if (vm_validate_args(args, "R--R--R--"))

	{
		vm_unfold_all(map, cur, &args, true);
//		cur->registr[args.nums[2]] = args.nums_unfolded[0] +
//				args.nums_unfolded[1];
		cur->registr[args.nums[2]] = (*operation)
				(args.nums_unfolded[0], args.nums_unfolded[1]);
		cur->carry = (cur->registr[args.nums[2]] == 0 ? 1 : 0);
//		if (cur->registr[args.nums[2]] == 0)
//			cur->carry = 1;
//		else
//			cur->carry = 0;
	}

	// cur->position += ft_move(args.types, "1110", args.dir_size) + 2;		ARGS ERROR commit
	/*
	cur->position += ft_move(args.types, "1110", args.dir_size) + 2;
	cur->position %= MEM_SIZE;
	*/
	map[cur->position][2] = 0;
	ft_move(cur, args.types, "1110", args.dir_size);
	map[cur->position][2] = 1;
	return (true);
}