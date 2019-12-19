//
// Created by Katharine Psylocke on 19/12/2019.
//

#include "vm.h"

int ft_add(unsigned char map[MEM_SIZE][4], t_cursor *car)
{
	unsigned int	args[4];
	unsigned char	reg1;
	unsigned char	reg2;
	unsigned char	reg3;

	ft_init_args(map, car->position, args);
	if (args[1] != REG_CODE || args[2] != REG_CODE || args[3] != REG_CODE)
		return (-1);
	reg1 = map[(car->position + 2) % MEM_SIZE][0] % 16;
	reg2 = map[(car->position + 3) % MEM_SIZE][0] % 16;
	reg3 = map[(car->position + 4) % MEM_SIZE][0] % 16;
	car->registr[reg3] = car->registr[reg1] + car->registr[reg2];
	car->carry = (car->registr[reg3] == 0 ? 1 : 0);
	car->position += 4;
	return (0);
}