/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:09:31 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:09:47 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	vm_op_st(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_args		args;
	int32_t		addr;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, cur, &args);
	if (cycle->log)
		vm_print_log_op("st", cycle);
//	if (cycle->cycle_num == 8159)
//		mvprintw(86, 90, "st target_cycle: %d", cycle->cycle_num);
		// if (vm_validate_args(args, "R--RI----"))						ARGS ERROR commit
	if (vm_validate_args(args, "R--RI----", 2))
	{
		vm_unfold_all(map, cur, &args, true);
		if (cycle->log)
			vm_print_log_args(&args, 2);
		if (args.types[1] == IND_CODE)
		{
			addr = (cur->position + args.nums[1]) % MEM_SIZE;
			if (addr < 0)
				addr += MEM_SIZE;
//			mvprintw(85, 16, "FREE PLACE! st ind: %d", args.nums_unfolded[1]);
//			mvprintw(86, 16, "FREE PLACE! st addr: %d", addr);
			vm_rewrite_map(map, cur, args.nums_unfolded[0], addr);
		}
		else if (args.types[1] == REG_CODE)
			cur->registr[args.nums[1]] = args.nums_unfolded[0];
	}
	else if (cycle->log)
		ft_putendl(" failed!");

	// cur->position += vm_move(args.types, "1100", 4) + 2;			ARGS ERROR commit
	//cur->position += vm_move(args.types, "1100", 4) + 2;
	//cur->position %= MEM_SIZE;
	map[cur->position][2] -= 1;
	vm_move(cur, args.types, "1100", 4);
	map[cur->position][2] += 1;
	return (true);
}
