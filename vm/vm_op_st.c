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


void	ft_rewrite_map(uint8_t map[MEM_SIZE][4],
t_cursor *car, unsigned int reg, int adress)
{
	map[(adress + 3) % MEM_SIZE][0] = reg;
	map[(adress + 3) % MEM_SIZE][1] = car->play_num + 2;
	map[(adress + 2) % MEM_SIZE][0] = reg >> 8;
	map[(adress + 2) % MEM_SIZE][1] = car->play_num + 2;
	map[(adress + 1) % MEM_SIZE][0] = reg >> 16;
	map[(adress + 1) % MEM_SIZE][1] = car->play_num + 2;
	map[adress % MEM_SIZE][0] = reg >> 24;
	map[adress % MEM_SIZE][1] = car->play_num + 2;
}

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

int		vm_op_st(uint8_t map[MEM_SIZE][4], t_cursor *car)
{
	uint8_t			args[4];
	t_ind			ind;
	unsigned int	reg;
	unsigned int	reg2;
	int				adress;

	ft_init_args(map, car->position, args);
	reg = map[(car->position + 2) % MEM_SIZE][0];
	reg2 = map[(car->position + 3) % MEM_SIZE][0];
	ft_init_t_ind(map, car->position + 3, &ind);
	adress = (car->position + ind.data % IDX_MOD) % MEM_SIZE;
	adress = (adress < 0 ? MEM_SIZE + adress : adress);
	if (ft_error_st(args, reg, reg2, car))
		return (1);
	if (args[1] == REG_CODE)
		car->registr[reg2] = car->registr[reg];
	else
		ft_rewrite_map(map, car, car->registr[reg], adress);
	car->position += ft_move(args, "1100", 4) + 2;
	car->position %= MEM_SIZE;
	return (1);
}
*/

bool	vm_op_st(uint8_t map[MEM_SIZE][4], t_cursor *car)
{
	t_args		args;
	int32_t		addr;

	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, car, &args);
	if (vm_validate_args(args, "R--RI----"))
	{
		if (args.types[1] == IND_CODE)
		{
			vm_unfold_all(map, car, &args, TRUE);
			addr = (car->position + args.nums_unfolded[1]) % MEM_SIZE;
			if (addr < 0)
				addr += MEM_SIZE;

		// mvprintw(86, 16, "FREE PLACE! addr: %d", addr);
		// mvprintw(87, 16, "FREE PLACE! reg: %d", args.nums[0]);
		// mvprintw(88, 16, "FREE PLACE! ->reg: %d", car->registr[args.nums[0]]);

			ft_rewrite_map(map, car, car->registr[args.nums[0]], addr);
		}
		else
			car->registr[args.nums[1]] = car->registr[args.nums[0]];
	}

//		ft_putstr("FREE PLACE! sti addr: blyat6");
	car->position += ft_move(args.types, "1100", 2) + 2;
	return (TRUE);
}