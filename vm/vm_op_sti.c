//
// Created by Katharine Psylocke on 24/12/2019.
//

#include "vm.h"

bool	vm_op_sti(uint8_t map[MEM_SIZE][4], t_cursor *car)
{
	t_args		args;
	int32_t		addr;

	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 2;
	vm_get_args(map, car, &args);
	if (vm_validate_args(args, "R--RIDR-D"))
	{
		vm_unfold_all(map, car, &args, FALSE);
		addr = (car->position + ((args.nums_unfolded[1] +
				args.nums_unfolded[2]) % IDX_MOD)) % MEM_SIZE;
		if (addr < 0)
			addr += MEM_SIZE;
//
//		mvprintw(86, 16, "FREE PLACE! sti addr: %d", (car->position + ((args.nums_unfolded[1] +args.nums_unfolded[2]) % IDX_MOD)) % MEM_SIZE);
//		mvprintw(87, 16, "FREE PLACE! sti car_pos: %d", car->position);
//		mvprintw(88, 16, "FREE PLACE! sti offset: %d", (args.nums_unfolded[1] + args.nums_unfolded[2]) % IDX_MOD);
//		mvprintw(89, 16, "FREE PLACE! sti 2 and 3 args: %d and %d", args.nums_unfolded[1], args.nums_unfolded[2]);
//		mvprintw(90, 16, "FREE PLACE! sti 2 and 3 types: %d and %d", args.types[1], args.types[2]);
//		mvprintw(91, 16, "FREE PLACE! sti 2 and 3 args folded: %d and %d", args.nums[1], args.nums[2]);
//
//
		ft_rewrite_map(map, car, car->registr[args.nums_unfolded[0]], addr);
	}
	car->position += ft_move(args.types, "1110", 2) + 2;
	return (TRUE);
}