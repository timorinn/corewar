/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:02:28 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 14:17:03 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline bool	op_load(uint8_t map[MEM_SIZE][4], bool is_idx_needed, t_cycle *cycle)
{
	t_args		args;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 2;
	if (is_idx_needed)
		args.dir_size += 2;
	vm_get_args(map, cur, &args);
	if (vm_validate_args(args, "-IDR-----"))
	{
		vm_unfold_all(map, cur, &args, is_idx_needed);
		cur->registr[args.nums[1]] = args.nums_unfolded[0];
		cur->carry = (cur->registr[args.nums[1]] == 0 ? 1 : 0);
	}
	cur->position += ft_move(args.types, "1100", args.dir_size) + 2;
	cur->position %= MEM_SIZE;
	return (true);
}
