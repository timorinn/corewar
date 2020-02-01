/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:02:28 by bford             #+#    #+#             */
/*   Updated: 2020/01/27 21:13:23 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

inline bool	op_load(uint8_t map[MEM_SIZE][4], bool is_idx_needed,
		t_cycle *cycle)
{
	t_args		args;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, cur, &args);
	if (vm_validate_args(args, "-IDR-----", 2))
	{
		vm_unfold_all(map, cur, &args, is_idx_needed);
		vm_print_log_args(&args, 2, cycle->log);
		cur->registr[args.nums[1]] = args.nums_unfolded[0];
		cur->carry = (cur->registr[args.nums[1]] == 0 ? 1 : 0);
	}
	else if (cycle->log == true)
		ft_putendl(" failed!");
	map[cur->position][2] -= 1;
	vm_move(cur, args.types, "1100", args.dir_size);
	map[cur->position][2] += 1;
	return (true);
}
