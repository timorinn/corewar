//
// Created by Katharine Psylocke on 23/12/2019.
//

#include "vm.h"

static void	get_reg(unsigned char map[MEM_SIZE][4], t_cursor *car,
					   t_args *args, int arg_num)
{
	args->nums[arg_num] = map[car->position + args->offset][0];
	args->offset += 1;
}

static void	get_dir(unsigned char map[MEM_SIZE][4], t_cursor *car,
					   t_args *args, int arg_num)
{
	t_dir	dir;

	ft_init_t_dir(map, car->position + args->offset, &dir, args->dir_size);
	args->nums[arg_num] = dir.data;
	args->offset += args->dir_size;
}

static void	get_ind(unsigned char map[MEM_SIZE][4], t_cursor *car,
					  t_args *args, int arg_num)
{
	t_ind	ind;

	ft_init_t_ind(map, car->position + args->offset, &ind);
	args->nums[arg_num] = ind.data;
	args->offset += IND_SIZE;
}

int			vm_get_args(unsigned char map[MEM_SIZE][4], t_cursor *car, t_args *args)
{
	int		i;

//	ft_bzero(nums, sizeof(int) * 2);
	ft_init_args(map, car->position, args->types);
	args->offset = 2;
	i = 0;
	while (i < 3)
	{
		if (args->types[i] == REG_CODE)
			get_reg(map, car, args, i);
		else if (args->types[i] == IND_CODE)
			get_ind(map, car, args, i);
		else if (args->types[i] == DIR_CODE)
			get_dir(map, car, args, i);
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}
