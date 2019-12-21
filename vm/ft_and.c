//
// Created by Katharine Psylocke on 20/12/2019.
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

static int	get_dir(unsigned char map[MEM_SIZE][4], t_cursor *car, int *offset)
{
	t_dir	dir;

	ft_init_t_dir(map, car->position + *offset, &dir);
	*offset += 4;
	return (dir.data);
}

static int	get_ind(unsigned char map[MEM_SIZE][4], t_cursor *car, int *offset)
{
	t_ind	ind;
	int		off;

	ft_init_t_ind(map, car->position + *offset, &ind);
	off = ind.data % IDX_MOD;
	*offset += 2;
	return (get_dir(map, car, &(off)));
}

int	get_nums(unsigned char map[MEM_SIZE][4], t_cursor *car,
		unsigned int args[4], int nums[3])
{
	int		reg;
	int		i;
	int 	offset;

//	ft_bzero(nums, sizeof(int) * 2);
	i = 0;
	offset = 2;
	while (i < 2)
	{
		if (args[i] == REG_CODE)
		{
			if ((reg = get_reg_num(map, car, offset)) == -1)
				return (-1);
			nums[i] = car->registr[reg];
			offset += 1;
		}
		else if (args[i] == IND_CODE)
			nums[i] = get_ind(map, car, &offset);
		else if (args[i] == DIR_CODE)
			nums[i] = get_dir(map, car, &offset);
		else
			return (-1);
		i++;
	}
	nums[2] = offset;
	return (0);
}

int ft_and(unsigned char map[MEM_SIZE][4], t_cursor *car)
{
	unsigned int	args[4];
	int 			nums[3];
	int				reg_num;

	ft_bzero(nums, sizeof(int) * 2);
	ft_init_args(map, car->position, args);
	if (args[2] == REG_CODE && (get_nums(map, car, args, nums)) != -1)
	{
		if ((reg_num = get_reg_num(map, car, nums[2])) != -1)
			car->registr[reg_num] = nums[0] & nums[1];
	}

	mvprintw(87, 16, "FREE PLACE! nums: = %d and %d", nums[0], nums[1]);

	car->position += ft_move(args, "1110", 4) + 2;

	car->position %= MEM_SIZE;
	return (1);
}