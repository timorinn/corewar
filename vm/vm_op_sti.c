/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:01:52 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 14:01:55 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	vm_op_sti(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_args		args;
	int32_t		addr;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 2;
	vm_get_args(map, cur, &args);
	if (vm_validate_args(args, "R--RIDR-D"))
	{
		vm_unfold_all(map, cur, &args, false);
		addr = (cur->position + (((int16_t)args.nums_unfolded[1] +
				(int16_t)args.nums_unfolded[2]) % IDX_MOD)) % MEM_SIZE;
		if (addr < 0)
			addr += MEM_SIZE;
//
		/*
		mvprintw(86, 16, "FREE PLACE! sti addr: %d", (car->position + ((args.nums_unfolded[1] +args.nums_unfolded[2]) % IDX_MOD)) % MEM_SIZE);
		mvprintw(87, 16, "FREE PLACE! sti car_pos: %d", car->position);
		mvprintw(88, 16, "FREE PLACE! sti offset: %d", (args.nums_unfolded[1] + args.nums_unfolded[2]) % IDX_MOD);
		mvprintw(89, 16, "FREE PLACE! sti offset without IDX: %d", (args.nums_unfolded[1] + args.nums_unfolded[2]));
		mvprintw(90, 16, "FREE PLACE! sti 2 and 3 args: %d and %d", args.nums_unfolded[1], args.nums_unfolded[2]);
		mvprintw(91, 16, "FREE PLACE! sti 2 and 3 types: %d and %d", args.types[1], args.types[2]);
		mvprintw(91, 16, "FREE PLACE! sti 2 and 3 args folded: %d and %d", args.nums[1], args.nums[2]);
		*/
//
//
		ft_rewrite_map(map, cur, args.nums_unfolded[0], addr);
	}
	cur->position += ft_move(args.types, "1110", 2) + 2;
	cur->position %= MEM_SIZE;
	return (true);
}