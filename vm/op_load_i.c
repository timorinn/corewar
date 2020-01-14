/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_load_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:02:32 by bford             #+#    #+#             */
/*   Updated: 2020/01/05 17:15:52 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline bool	op_load_i(uint8_t map[MEM_SIZE][4], bool ll, t_cycle *cycle)
{
	t_args		args;
	int32_t		addr;
	int32_t 	offset;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 2;
	vm_get_args(map, cur, &args);
	if (cycle->cycle_num == 8704)
		mvprintw(101, 90, "ldi target_cycle: %d", cycle->cycle_num);

	// if (vm_validate_args(args, "RIDR-DR--"))										ARGS ERROR commit
	if (vm_validate_args(args, "RIDR-DR--", 3))

	{
		vm_unfold_all(map, cur, &args, true);
//		offset = args.nums_unfolded[0] + args.nums_unfolded[1];
		offset = (args.nums_unfolded[0] + args.nums_unfolded[1]);
		if (ll == false)
			offset %= IDX_MOD;
		addr = (cur->position + offset) % MEM_SIZE;
		if (addr < 0)
			addr += MEM_SIZE;
		cur->registr[args.nums[2]] = ft_init_t_dir(map, addr, 4).data;
	}

	// cur->position += ft_move(args.types, "1110", 2) + 2;							ARGS ERROR commit
	/*
	cur->position += ft_move(args.types, "1110", 2) + 2;
	cur->position %= MEM_SIZE;
	*/
	map[cur->position][2] -= 1;
	ft_move(cur, args.types, "1110", 2);
	map[cur->position][2] += 1;
	return (true);
}
