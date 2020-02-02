/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_unfold_indirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:47:37 by bford             #+#    #+#             */
/*   Updated: 2020/01/29 17:11:33 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	vm_unfold_indirect(uint8_t map[MEM_SIZE][4],
		uint16_t addr, uint8_t dir_size)
{
	t_dir		dir;

	addr %= MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	dir = vm_init_t_dir(map, addr, dir_size);
	return (dir.data);
}

void				vm_unfold_all(uint8_t map[MEM_SIZE][4], t_cursor *car,
		t_args *args, bool is_idx_needed)
{
	int		i;
	int32_t	addr;

	i = 0;
	while (i < 3)
	{
		if (args->types[i] == IND_CODE)
		{
			if (is_idx_needed)
				args->nums[i] %= IDX_MOD;
			addr = car->position + args->nums[i];
			if (!is_idx_needed)
				addr %= IDX_MOD;
			args->nums_unfolded[i] = vm_unfold_indirect(map,
					addr, args->dir_size);
		}
		else if (args->types[i] == REG_CODE)
			args->nums_unfolded[i] = car->registr[args->nums[i]];
		else if (args->types[i] == DIR_CODE)
			args->nums_unfolded[i] = args->nums[i];
		i++;
	}
}
