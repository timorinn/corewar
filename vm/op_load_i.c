/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_load_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:02:32 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 14:43:26 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	op_load_i(uint8_t map[MEM_SIZE][4], bool ll, t_cycle *cycle)
{
	t_args		args;
	int32_t		addr;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 2;
	vm_get_args(map, cur, &args);
	if (vm_validate_args(args, "RIDR-DR--"))
	{
		vm_unfold_all(map, cur, &args, true);
		addr = ((int16_t)args.nums_unfolded[0] + (int16_t)args.nums_unfolded[1]);
		if (!ll)
			addr %= IDX_MOD;
		addr = (addr + cur->position) % MEM_SIZE;
		if (addr < 0)
			addr += MEM_SIZE;
		cur->registr[args.nums[2]] = ft_init_t_dir(map, addr, 4).data;
	}
	cur->position += ft_move(args.types, "1110", 2) + 2;
	cur->position %= MEM_SIZE;
	return (true);
}
