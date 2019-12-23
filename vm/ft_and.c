//
// Created by Katharine Psylocke on 20/12/2019.
//

#include "vm.h"



bool	ft_and(unsigned char map[MEM_SIZE][4], t_cursor *car)
{
	t_args 			args;

	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, car, &args);
	if (vm_validate_args(args, "RIDRIDR--"))
	{
		vm_unfold_all(map, car, &args, TRUE);
		car->registr[args.nums[2]] = args.nums_unfolded[0] &
				args.nums_unfolded[1];
		if (car->registr[args.nums[2]] == 0)
			car->carry = 1;
		else
			car->carry = 0;
	}
	car->position += ft_move(args.types, "1110", 4) + 2;
	car->position %= MEM_SIZE;
	return (TRUE);
}
