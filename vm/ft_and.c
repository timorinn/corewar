//
// Created by Katharine Psylocke on 20/12/2019.
//

#include "vm.h"



int ft_and(unsigned char map[MEM_SIZE][4], t_cursor *car)
{
	t_args 			args;
	int				reg_num;

	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, car, &args);
	if (args.types[2] == REG_CODE)
	{

	}

	mvprintw(87, 16, "FREE PLACE! nums: = %d and %d", nums[0], nums[1]);

	car->position += ft_move(args, "1110", 4) + 2;

	car->position %= MEM_SIZE;
	return (1);
}