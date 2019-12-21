//
// Created by Katharine Psylocke on 20/12/2019.
//

#include "vm.h"

inline static int	validate_regs(unsigned int r1, unsigned int r2,
								   unsigned int r3)
{
	if (r1 <= REG_NUMBER && r2 <= REG_NUMBER && r3 <= REG_NUMBER)
	{
		if (r1 > 0 && r2 > 0 && r3 > 0)
			return (0);
	}
	return (1);
}

int					ft_sub(unsigned char map[MEM_SIZE][4], t_cursor *car)
{
	unsigned int	args[4];
	unsigned int	reg1;
	unsigned int	reg2;
	unsigned int	reg3;

	ft_init_args(map, car->position, args);
	if (args[1] == REG_CODE && args[2] == REG_CODE && args[3] == REG_CODE)
	{
		reg1 = map[(car->position + 2) % MEM_SIZE][0];
		reg2 = map[(car->position + 3) % MEM_SIZE][0];
		reg3 = map[(car->position + 4) % MEM_SIZE][0];
		if (validate_regs(reg1, reg2, reg3) == 0)
		{
			car->registr[reg3] = car->registr[reg1] - car->registr[reg2];
			car->carry = (car->registr[reg3] == 0 ? 1 : 0);
		}
	}
	car->position += ft_move(args, "1110", 4) + 2;
	car->position %= MEM_SIZE;
	return (1);
}