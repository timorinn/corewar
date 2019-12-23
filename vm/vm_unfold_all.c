//
// Created by Katharine Psylocke on 23/12/2019.
//

#include "vm.h"

int			vm_unfold_indirect(unsigned char map[MEM_SIZE][4], uint16_t addr,
								  bool is_idx_needed, uint8_t dir_size)
{
	t_dir		dir;

	if (is_idx_needed == TRUE)
		addr %= IDX_MOD;
	if (addr < 0)
		addr += MEM_SIZE;
	ft_init_t_dir(map, addr, &dir, dir_size);
	return (dir.data);
}

void		vm_unfold_all(unsigned char map[MEM_SIZE][4], t_cursor *car,
						  t_args *args, bool is_idx_needed)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (args->types[i] == IND_CODE)
			args->nums_unfolded[i] = vm_unfold_indirect(map, car->position +
					args->nums[i], is_idx_needed, args->dir_size);
		else if (args->types[i] == REG_CODE)
			args->nums_unfolded[i] = car->registr[args->nums[i]];
		else if (args->types[i] == DIR_CODE)
			args->nums_unfolded[i] = args->nums[i];
		i++;
	}
}