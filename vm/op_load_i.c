//
// Created by Katharine Psylocke on 24/12/2019.
//

#include "vm.h"

bool	op_load_i(uint8_t map[MEM_SIZE][4], t_cursor *car, bool ll)
{
	t_args		args;
	int16_t		addr;

	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 2;
	vm_get_args(map, car, &args);
	if (vm_validate_args(args, "RIDR-DR--"))
	{
		vm_unfold_all(map, car, &args, true);
		addr = ((int16_t)args.nums_unfolded[0] + (int16_t)args.nums_unfolded[1]);
		if (!ll)
			addr %= IDX_MOD;
		addr = (addr + car->position) % MEM_SIZE;
		if (addr < 0)
			addr += MEM_SIZE;
		car->registr[args.nums[2]] = ft_init_t_dir(map, addr, args.dir_size).data;
	}
	car->position += ft_move(args.types, "1110", 2) + 2;
	car->position %= MEM_SIZE;
	return (true);
}
