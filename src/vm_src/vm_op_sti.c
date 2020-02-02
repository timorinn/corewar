/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:01:52 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 13:24:01 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	vm_print_log_sti(t_args *args, int32_t addr, t_cycle *cycle)
{
	int32_t offset;

	if (cycle->log == false)
		return ;
	offset = args->nums_unfolded[1] + args->nums_unfolded[2];
	ft_printf("%20c -> store to %d + %d = %d (with pc and mod %d)\n", '|',
			args->nums_unfolded[1], args->nums_unfolded[2], offset, addr);
}

static void	init_args(uint8_t map[MEM_SIZE][4],
								t_cursor *cur, t_args *args)
{
	ft_bzero(args, sizeof(t_args));
	args->dir_size = 2;
	vm_get_args(map, cur, args);
	args->dir_size += 2;
}

bool				vm_op_sti(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_args		args;
	int32_t		addr;
	int32_t		offset;
	t_cursor	*cur;

	cur = cycle->now_cur;
	init_args(map, cur, &args);
	vm_print_log_op("sti", cycle);
	if (vm_validate_args(args, "R--RIDR-D", 3))
	{
		vm_unfold_all(map, cur, &args, false);
		vm_print_log_args(&args, 3, cycle->log);
		offset = args.nums_unfolded[1] + args.nums_unfolded[2];
		addr = (cur->position + (offset % IDX_MOD)) % MEM_SIZE;
		addr += (addr < 0 ? MEM_SIZE : 0);
		vm_print_log_sti(&args, addr, cycle);
		vm_rewrite_map(map, cur, args.nums_unfolded[0], addr);
	}
	else if (cycle->log)
		ft_putendl(" failed!");
	map[cur->position][2] -= 1;
	vm_move(cur, args.types, "1110", 2);
	map[cur->position][2] += 1;
	return (true);
}
