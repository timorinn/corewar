/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:01:52 by bford             #+#    #+#             */
/*   Updated: 2020/01/05 17:17:10 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static inline void	vm_print_log_sti(t_args *args, int32_t addr)
{
	int32_t offset;

	offset = args->nums_unfolded[1] + args->nums_unfolded[2];
	ft_printf("%20c -> store to %d + %d = %d (with pc and mod %d)\n", '|', args->nums_unfolded[1], args->nums_unfolded[2], offset, addr);
	fflush(stdout);
}

bool				vm_op_sti(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_args		args;
	int32_t		addr;
	int32_t		offset;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 2;
	vm_get_args(map, cur, &args);
	if (cycle->log)
		vm_print_log_op("sti", cycle);
	// if (vm_validate_args(args, "R--RIDR-D"))							ARGS ERROR commit
	if (vm_validate_args(args, "R--RIDR-D", 3))

	{
//
//		if (cycle->cycle_num == 8729)
//			mvprintw(86, 90, "sti target_cycle: %d", cycle->cycle_num);

		vm_unfold_all(map, cur, &args, false);
		if (cycle->log == true)
			vm_print_log_args(&args, 3);
//		if (cycle->cycle_num == 8194 && cur->position == 3330)
//			args.nums_unfolded[1] = args.nums_unfolded[0];
//		if (cycle->cycle_num >= 8193 && cycle->cycle_num <= 8199)
//			args.nums_unfolded[1] = -173;
		offset = args.nums_unfolded[1] + args.nums_unfolded[2];
		addr = (cur->position + (offset % IDX_MOD)) % MEM_SIZE;
//		addr = (cur->position + ((args.nums_unfolded[1] +
//								  args.nums_unfolded[2]) % IDX_MOD)) % MEM_SIZE;
		if (addr < 0)
			addr += MEM_SIZE;
		/*
		move(85, 0);
		clrtobot();
		mvprintw(86, 16, "sti addr: %d", addr);
		mvprintw(87, 16, "sti car_pos: %d", cur->position);
		mvprintw(88, 16, "sti offset: %d", (args.nums_unfolded[1] + args.nums_unfolded[2]) % IDX_MOD);
		mvprintw(89, 16, "sti offset without IDX: %d", (args.nums_unfolded[1] + args.nums_unfolded[2]));
		mvprintw(90, 16, "sti 2 and 3 args: %d and %d", args.nums_unfolded[1], args.nums_unfolded[2]);
		mvprintw(91, 16, "sti 2 and 3 types: %d and %d", args.types[1], args.types[2]);
		mvprintw(92, 16, "sti 2 and 3 args folded: %d and %d", args.nums[1], args.nums[2]);
		mvprintw(93, 16, "sti to be written (in reg): %08x", args.nums_unfolded[0]);

		mvprintw(94, 16, "byte from addr: %02x", (int)(map[(addr + 3) % MEM_SIZE][0]));
		mvprintw(95, 16, "byte from addr: %02x", (int)(map[(addr + 2) % MEM_SIZE][0]));
		mvprintw(96, 16, "byte from addr: %02x", (int)(map[(addr + 1) % MEM_SIZE][0]));
		mvprintw(97, 16, "byte from addr: %02x", (int)(map[(addr + 0) % MEM_SIZE][0]));

		*/
		if (cycle->log)
			vm_print_log_sti(&args, addr);
		vm_rewrite_map(map, cur, args.nums_unfolded[0], addr);

/*
		mvprintw(94, 50, "byte from addr: %02x", (int)(map[(addr + 3) % MEM_SIZE][0]));
		mvprintw(95, 50, "byte from addr: %02x", (int)(map[(addr + 2) % MEM_SIZE][0]));
		mvprintw(96, 50, "byte from addr: %02x", (int)(map[(addr + 1) % MEM_SIZE][0]));
		mvprintw(97, 50, "byte from addr: %02x", (int)(map[(addr + 0) % MEM_SIZE][0]));
*/
	}
	else if (cycle->log)
		ft_putendl(" failed!");

	// cur->position += vm_move(args.types, "1110", 2) + 2; 			ARGS ERROR commit
	/*
	cur->position += vm_move(args.types, "1110", 2) + 2;
	cur->position %= MEM_SIZE;
	*/
	map[cur->position][2] -= 1;
	vm_move(cur, args.types, "1110", 2);
	map[cur->position][2] += 1;
	return (true);
}
