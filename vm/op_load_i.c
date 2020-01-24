/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_load_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:02:32 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:55:38 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static inline void	vm_print_log_ldi(t_args *args, int32_t addr)
{
	int32_t offset;

	offset = args->nums_unfolded[0] + args->nums_unfolded[1];
	ft_printf("%20c -> load from %d + %d = %d (with pc and mod %d)\n", '|',
			args->nums_unfolded[0], args->nums_unfolded[1], offset, addr);
}

inline bool			op_load_i(uint8_t map[MEM_SIZE][4], bool ll, t_cycle *cycle)
{
	t_args		args;
	int32_t		addr;
	int32_t		offset;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 2;
	vm_get_args(map, cur, &args);
	args.dir_size += 2;
	if (vm_validate_args(args, "RIDR-DR--", 3))
	{
		vm_unfold_all(map, cur, &args, true);
//		offset = args.nums_unfolded[0] + args.nums_unfolded[1];
		if (cycle->log == true)
			vm_print_log_args(&args, 3);
		offset = (args.nums_unfolded[0] + args.nums_unfolded[1]);
		if (ll == false)
			offset %= IDX_MOD;
		addr = (cur->position + offset) % MEM_SIZE;
		if (addr < 0)
			addr += MEM_SIZE;
		cur->registr[args.nums[2]] = vm_init_t_dir(map, addr, 4).data;
		if (cycle->log)
			vm_print_log_ldi(&args, addr);
	}
	else if (cycle->log == true)
		ft_putendl(" failed!");
	map[cur->position][2] -= 1;
	vm_move(cur, args.types, "1110", 2);
	map[cur->position][2] += 1;
	return (true);
}
