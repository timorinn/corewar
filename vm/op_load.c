//
// Created by Katharine Psylocke on 24/12/2019.
//

#include "vm.h"

inline bool	op_load(uint8_t map[MEM_SIZE][4], t_cursor *car, bool is_idx_needed)
{
	t_args		args;

	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 2;
	if (is_idx_needed)
		args.dir_size += 2;
	vm_get_args(map, car, &args);
	if (vm_validate_args(args, "-IDR-----"))
	{
		vm_unfold_all(map, car, &args, is_idx_needed);
		car->registr[args.nums[1]] = args.nums_unfolded[0];
		car->carry = (car->registr[args.nums[1]] == 0 ? 1 : 0);
	}
	car->position += ft_move(args.types, "1100", args.dir_size) + 2;
	car->position %= MEM_SIZE;
	return (true);
}
