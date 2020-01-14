/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:49:21 by stasyan           #+#    #+#             */
/*   Updated: 2019/12/19 16:07:35 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
int		ft_error_st(uint8_t args[4], int reg, int reg2, t_cursor *car)
{
	if (args[0] != REG_CODE || (args[1] != REG_CODE && args[1] != IND_CODE) ||
	reg < 1 || reg > 16 || (args[1] == REG_CODE && (reg2 < 1 || reg2 > 16)))
	{
		car->position += ft_move(args, "1100", 4) + 2;
		car->position %= MEM_SIZE;
		return (1);
	}
	return (0);
}

bool	vm_op_st(uint8_t map[MEM_SIZE][4], t_cursor *car)
{
	uint8_t			args[4];
	t_ind			ind;
	unsigned int	reg;
	unsigned int	reg2;
	int				adress;

	ft_init_args(map, car->position, args);
	reg = map[(car->position + 2) % MEM_SIZE][0] + 1;
	reg2 = map[(car->position + 3) % MEM_SIZE][0] + 1;
	ft_init_t_ind(map, car->position + 3, &ind);
	adress = (car->position + ind.data % IDX_MOD) % MEM_SIZE;
	adress = (adress < 0 ? MEM_SIZE + adress : adress);
	if (ft_error_st(args, reg, reg2, car))
		return (1);
	if (args[1] == REG_CODE)
		car->registr[reg2] = car->registr[reg];
	else
		ft_rewrite_map(map, car, car->registr[reg], adress);
	mvprintw(86, 16, "FREE PLACE! old st addr: %d", adress);
	car->position += ft_move(args, "1100", 4) + 2;
	car->position %= MEM_SIZE;
	return (1);
}
*/

bool	vm_op_st(uint8_t map[MEM_SIZE][4], t_cycle *cycle)
{
	t_args		args;
	int32_t		addr;
	t_cursor	*cur;

	cur = cycle->now_cur;
	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, cur, &args);

//	if (cycle->cycle_num == 8159)
//		mvprintw(86, 90, "st target_cycle: %d", cycle->cycle_num);
		// if (vm_validate_args(args, "R--RI----"))						ARGS ERROR commit
	if (vm_validate_args(args, "R--RI----", 2))

	{
		vm_unfold_all(map, cur, &args, true);
		if (args.types[1] == IND_CODE)
		{
			addr = (cur->position + args.nums[1]) % MEM_SIZE;
			if (addr < 0)
				addr += MEM_SIZE;
//			mvprintw(85, 16, "FREE PLACE! st ind: %d", args.nums_unfolded[1]);
//			mvprintw(86, 16, "FREE PLACE! st addr: %d", addr);
			ft_rewrite_map(map, cur, args.nums_unfolded[0], addr);
		}
		else if (args.types[1] == REG_CODE)
			cur->registr[args.nums[1]] = args.nums_unfolded[0];
	}

	// cur->position += ft_move(args.types, "1100", 4) + 2;			ARGS ERROR commit
	//cur->position += ft_move(args.types, "1100", 4) + 2;
	//cur->position %= MEM_SIZE;
	map[cur->position][2] -= 1;
	ft_move(cur, args.types, "1100", 4);
	map[cur->position][2] += 1;
	return (true);
}
