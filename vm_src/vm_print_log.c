/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:09:52 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 13:22:41 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_print_log_op(char *op, t_cycle *cycle)
{
	if (cycle->log == false)
		return ;
	ft_printf("P % 4d, pos = %-4d | %s",
			cycle->now_cur->num, cycle->now_cur->position, op);
}

void	vm_print_log_args(t_args *args, uint8_t max_args, t_cycle *cycle)
{
	uint8_t i;

	i = 0;
	if (cycle->log == false)
		return ;
	while (i < max_args)
	{
		if (args->types[i] == REG_CODE)
			ft_printf(" r%d(%d)", args->nums[i], args->nums_unfolded[i]);
		else if (args->types[i] == DIR_CODE)
			ft_printf(" %d", args->nums[i]);
		else if (args->types[i] == IND_CODE)
			ft_printf(" ind%d,unfolded %d",
					args->nums[i], args->nums_unfolded[i]);
		else
			ft_printf("Error has happened here. Args types: %d %d %d    ",
					args->types[0], args->types[1], args->types[2]);
		i++;
	}
	ft_putendl("");
}
