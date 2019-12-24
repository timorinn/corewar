//
// Created by Katharine Psylocke on 23/12/2019.
//

#include "vm.h"

static inline int	vm_unfold_indirect(uint8_t map[MEM_SIZE][4], uint16_t addr, uint8_t dir_size)
{
	t_dir		dir;

	if (addr < 0)
		addr += MEM_SIZE;
	ft_init_t_dir(map, addr, &dir, dir_size);
	return (dir.data);
}

void				vm_unfold_all(uint8_t map[MEM_SIZE][4], t_cursor *car,
							  t_args *args, bool is_idx_needed)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (args->types[i] == IND_CODE)
		{
			if (is_idx_needed)
				args->nums[i] %= IDX_MOD;
			args->nums_unfolded[i] = vm_unfold_indirect(map, car->position +
					args->nums[i], args->dir_size);
		}
		else if (args->types[i] == REG_CODE)
			args->nums_unfolded[i] = car->registr[args->nums[i]];
		else if (args->types[i] == DIR_CODE)
			args->nums_unfolded[i] = args->nums[i];
		i++;
	}
}
