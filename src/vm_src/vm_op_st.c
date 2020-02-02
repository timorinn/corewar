/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:09:31 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 13:33:33 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	handle_indirect(uint8_t map[MEM_SIZE][4], t_args *args,
		t_cursor *cur)
{
	int32_t		addr;

	addr = (cur->position + args->nums[1]) % MEM_SIZE;
	addr += (addr < 0 ? MEM_SIZE : 0);
	vm_rewrite_map(map, cur, args->nums_unfolded[0], addr);
}

bool				vm_op_st(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_args		args;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, cur, &args);
	vm_print_log_op("st", cycle);
	if (vm_validate_args(args, "R--RI----", 2))
	{
		vm_unfold_all(map, cur, &args, true);
		vm_print_log_args(&args, 2, cycle->log);
		if (args.types[1] == IND_CODE)
			handle_indirect(map, &args, cur);
		else if (args.types[1] == REG_CODE)
			cur->registr[args.nums[1]] = args.nums_unfolded[0];
	}
	else if (cycle->log)
		ft_putendl(" failed!");
	map[cur->position][2] -= 1;
	vm_move(cur, args.types, "1100", 4);
	map[cur->position][2] += 1;
	return (true);
}
