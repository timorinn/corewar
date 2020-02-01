/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 17:53:10 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 14:12:50 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

inline bool	op_add_sub(uint8_t map[MEM_SIZE][4],
		int32_t (*operation)(int32_t, int32_t), t_cycle *cycle)
{
	t_args		args;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, cur, &args);
	if (vm_validate_args(args, "R--R--R--", 3))
	{
		vm_unfold_all(map, cur, &args, true);
		vm_print_log_args(&args, 3, cycle->log);
		cur->registr[args.nums[2]] = (*operation)
(args.nums_unfolded[0], args.nums_unfolded[1]);
		cur->carry = (cur->registr[args.nums[2]] == 0 ? 1 : 0);
	}
	else if (cycle->log == true)
		ft_putendl(" failed!");
	map[cur->position][2] -= 1;
	vm_move(cur, args.types, "1110", args.dir_size);
	map[cur->position][2] += 1;
	return (true);
}
