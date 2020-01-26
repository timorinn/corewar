/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_load_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:02:32 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 14:09:10 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static inline void	vm_print_log_ldi(t_args *args, int32_t addr,
		t_cycle *cycle)
{
	int32_t offset;

	if (cycle->log == false)
		return ;
	offset = args->nums_unfolded[0] + args->nums_unfolded[1];
	ft_printf("%20c -> load from %d + %d = %d (with pc and mod %d)\n", '|',
			args->nums_unfolded[0], args->nums_unfolded[1], offset, addr);
}

inline static void	init_args(uint8_t map[MEM_SIZE][4],
		t_cursor *cur, t_args *args)
{
	ft_bzero(args, sizeof(t_args));
	args->dir_size = 2;
	vm_get_args(map, cur, args);
	args->dir_size += 2;
}

inline bool			op_load_i(uint8_t map[MEM_SIZE][4],
		bool ll, t_cycle *cycle)
{
	t_args		args;
	int32_t		addr;
	int32_t		offset;
	t_cursor	*cur;

	cur = cycle->now_cur;
	init_args(map, cur, &args);
	if (vm_validate_args(args, "RIDR-DR--", 3))
	{
		vm_unfold_all(map, cur, &args, true);
		vm_print_log_args(&args, 3, cycle->log);
		offset = (args.nums_unfolded[0] + args.nums_unfolded[1]);
		offset %= (ll == false ? IDX_MOD : (offset + 1));
		addr = (cur->position + offset) % MEM_SIZE;
		addr += (addr < 0 ? MEM_SIZE : 0);
		cur->registr[args.nums[2]] = vm_init_t_dir(map, addr, 4).data;
		vm_print_log_ldi(&args, addr, cycle);
	}
	else if (cycle->log == true)
		ft_putendl(" failed!");
	map[cur->position][2] -= 1;
	vm_move(cur, args.types, "1110", 2);
	map[cur->position][2] += 1;
	return (true);
}
