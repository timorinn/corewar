/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:38:15 by kpsylock          #+#    #+#             */
/*   Updated: 2019/12/31 23:36:28 by bford            ###   ########.fr       */
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
	if (vm_validate_args(args, "RIDRIDR--"))

	{
		vm_unfold_all(map, cur, &args, true);
		cur->registr[args.nums[2]] = (*operation)
				(args.nums_unfolded[0], args.nums_unfolded[1]);
		cur->carry = (cur->registr[args.nums[2]] == 0 ? 1 : 0);
	}

	// cur->position += ft_move(args.types, "1110", 4) + 2;		ARGS ERROR commit
	cur->position += ft_move(args.types, "1110", 4) + 2;
	
	cur->position %= MEM_SIZE;
	return (true);
}
