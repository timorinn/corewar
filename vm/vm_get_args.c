//
// Created by Katharine Psylocke on 23/12/2019.
//

#include "vm.h"

static void	get_reg(unsigned char map[MEM_SIZE][4], t_cursor *car,
					   t_args *args, int arg_num)
{
	args->nums[arg_num] = map[car->position + args->total_offset][0];
	if (arg_num == 0)
		args->offsets[arg_num] = 1;
	else
		args->offsets[arg_num] = args->offsets[arg_num - 1] + 1;
	args->total_offset += args->offsets[arg_num];
}

static void	get_dir(unsigned char map[MEM_SIZE][4], t_cursor *car,
					   t_args *args, int arg_num)
{
	t_dir	dir;

	ft_init_t_dir(map, car->position + args->total_offset, &dir, args->dir_size);
	args->nums[arg_num] = dir.data;
	if (arg_num == 0)
		args->offsets[arg_num] = args->dir_size;
	else
		args->offsets[arg_num] = args->offsets[arg_num - 1] + args->dir_size;
	args->total_offset += args->offsets[arg_num];
}

static void	get_ind(unsigned char map[MEM_SIZE][4], t_cursor *car,
					  t_args *args, int arg_num)
{
	t_ind	ind;

	ft_init_t_ind(map, car->position + args->total_offset, &ind);
	args->nums[arg_num] = ind.data;
	if (arg_num == 0)
		args->offsets[arg_num] = IND_SIZE;
	else
		args->offsets[arg_num] = args->offsets[arg_num - 1] + IND_SIZE;
	args->total_offset += args->offsets[arg_num];
}

int			vm_get_args(unsigned char map[MEM_SIZE][4], t_cursor *car, t_args *args)
{
	int		i;

//	ft_bzero(nums, sizeof(int) * 2);
	ft_init_args(map, car->position, args->types);
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
