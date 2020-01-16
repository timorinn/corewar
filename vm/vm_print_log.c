//
// Created by Katharine Psylocke on 16/01/2020.
//

#include "vm.h"

void	vm_print_log_op(char *op, t_cycle *cycle)
{
	///////ft_printf!!
	printf("P % 4d, pos = %-4d | %s", cycle->now_cur->num, cycle->now_cur->position, op);
	fflush(stdout);
}

void	vm_print_log_args(t_args *args, uint8_t max_args)
{
	//////////////ft_printf!!

	uint8_t i;

	i = 0;
	while (i < max_args)
	{
		if (args->types[i] == REG_CODE)
			printf(" r%d(%d)", args->nums[i], args->nums_unfolded[i]);
		else if (args->types[i] == DIR_CODE)
			printf(" %d", args->nums[i]);
		else if (args->types[i] == IND_CODE)
			printf(" ind%d,unfolded %d", args->nums[i], args->nums_unfolded[i]);
		i++;
	}
	fflush(stdout);
	ft_putendl("");
}

