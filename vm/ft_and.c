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
	else
		return (-1);
}

static int	get_dir(unsigned char map[MEM_SIZE][4], t_cursor *car,)
{

	return 0;
}

int	get_nums(unsigned char map[MEM_SIZE][4], t_cursor *car,
		unsigned int args[4], int nums[2])
{
	int		reg;
	int		i;
	t_ind	ind;
	t_dir 	dir;
	int 	offset;

	ft_bzero(nums, sizeof(int) * 2);
	i = 0;
	offset = 2;
	while (i < 2)
	{
		ft_bzero(&ind, sizeof(t_ind));
		if (args[i] == REG_CODE)
		{
			reg = get_reg_num(map, car, offset);
			if (reg == -1)
				return (-1);
			nums[i] = car->registr[reg];
			offset += 1;
			continue ;
		}
		if (args[i] == IND_CODE)
			ft_init_t_ind(map, car->position, &ind);
		if (args[i] != IND_CODE && args[i] != DIR_CODE)
			return (-1);
		ft_init_t_dir(map, car->position + offset + ind.data, &dir);
		nums[i] = dir.data;
		offset += (args[i] == DIR_CODE ? 4 : 2);
		i++;
	}
	return (0);
}

int ft_and(unsigned char map[MEM_SIZE][4], t_cursor *car)
{
	unsigned int	args[4];
	int 			nums[3];


	ft_init_args(map, car->position, args);

	// some magic

	car->position += ft_move(args, "1110", 4) + 2;
	car->position %= MEM_SIZE;
}