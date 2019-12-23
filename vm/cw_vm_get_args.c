//
// Created by Katharine Psylocke on 23/12/2019.
//

#include "vm.h"

inline static int	get_reg_num(unsigned char map[MEM_SIZE][4], t_cursor *car,
								 int offset)
{
	int reg;

	reg = map[(car->position + offset) % MEM_SIZE][0];
	if (reg > 0 && reg <= REG_NUMBER)
		return (reg);
	return (-1);
}

static void	get_dir(unsigned char map[MEM_SIZE][4], t_cursor *car,
					   t_args *args, int arg_num)
{
	t_dir	dir;

	ft_init_t_dir(map, car->position + args->total_offset, &dir);
	args->nums[arg_num] = dir.data;
	args->offsets[arg_num] = args->offsets[arg_num - 1] + args->dir_size;
	args->total_offset += args->offsets[arg_num];
}

static int	get_ind(unsigned char map[MEM_SIZE][4], t_cursor *car,
					  t_args *args, int arg_num)
{
	t_ind	ind;
	int		ind_offset;

	ft_init_t_ind(map, car->position + args->total_offset, &ind);
	if (args->idx)
		ind_offset = ind.data % IDX_MOD;
	*offset += 2;
	return (get_dir(map, car, &(off)));
}

int	cw_vm_get_args(unsigned char map[MEM_SIZE][4], t_cursor *car, t_args *args)
{
	int		reg;
	int		i;
	int 	offset;

//	ft_bzero(nums, sizeof(int) * 2);
	ft_init_args(map, car->position, args->types);
	i = 0;
	offset = 2;
	while (i < 4)
	{
		if (args->types[i] == REG_CODE)
		{
			if ((reg = get_reg_num(map, car, offset)) == -1)
				return (FALSE);
			nums[i] = car->registr[reg];
			offset += 1;
		}
		else if (args->types[i] == IND_CODE)
			get_ind(map, car, args, i);
		else if (args->types[i] == DIR_CODE)
			get_dir(map, car, args, i);
		else
			return (FALSE);
		i++;
	}
	nums[2] = offset;
	return (TRUE);
}