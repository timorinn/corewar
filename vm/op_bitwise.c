/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:38:15 by kpsylock          #+#    #+#             */
/*   Updated: 2020/01/05 17:15:18 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline bool	op_bitwise(uint8_t map[MEM_SIZE][4],
					int32_t (*operation)(int32_t, int32_t), t_cycle *cycle)
{
	t_args 		args;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, cur, &args);

	// if (vm_validate_args(args, "RIDRIDR--"))					ARGS ERROR commit
	if (vm_validate_args(args, "RIDRIDR--", 3))
	{
		vm_unfold_all(map, cur, &args, true);
		mvprintw(80, 16, "target reg index: %08x", args.nums[2]);
		mvprintw(81, 16, "target reg: %08x", cur->registr[args.nums[2]]);
		mvprintw(82, 16, "first reg: %08x", args.nums_unfolded[0]);
		mvprintw(83, 16, "second reg: %08x", args.nums_unfolded[1]);
//		mvprintw(79, 16, "OR/XOR/AND");

		cur->registr[args.nums[2]] = (*operation)
				(args.nums_unfolded[0], args.nums_unfolded[1]);
		mvprintw(84, 16, "result in target reg: %08x", cur->registr[args.nums[2]]);
		cur->carry = (cur->registr[args.nums[2]] == 0 ? 1 : 0);
	}

	// cur->position += ft_move(args.types, "1110", 4) + 2;		ARGS ERROR commit
	/*
	cur->position += ft_move(args.types, "1110", 4) + 2;
	cur->position %= MEM_SIZE;
	*/
	map[cur->position][2] -= 1;
	ft_move(cur, args.types, "1110", 4);
	map[cur->position][2] += 1;
	return (true);
}
