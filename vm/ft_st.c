/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:49:21 by stasyan           #+#    #+#             */
/*   Updated: 2019/12/19 16:07:35 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_rewrite_map(unsigned char map[4096][4],
careta *car, unsigned int reg, int adress)
{
	map[(adress + 3) % 4096][0] = reg;
	map[(adress + 3) % 4096][1] = car->play_num + 2;
	map[(adress + 2) % 4096][0] = reg >> 8;
	map[(adress + 2) % 4096][1] = car->play_num + 2;
	map[(adress + 1) % 4096][0] = reg >> 16;
	map[(adress + 1) % 4096][1] = car->play_num + 2;
	map[adress % 4096][0] = reg >> 24;
	map[adress % 4096][1] = car->play_num + 2;
	return (1);
}

int		ft_error_st(unsigned int args[4], int reg, int reg2, careta *car)
{
	if (args[0] != REG_CODE || (args[1] != REG_CODE && args[1] != IND_CODE) ||
	reg < 1 || reg > 16 || (args[1] == REG_CODE && (reg2 < 1 || reg2 > 16)))
	{
		car->position += ft_move(args, "1100", 4) + 2;
		car->position %= 4096;
		return (1);
	}
	return (0);
}

int		ft_st(unsigned char map[4096][4], careta *car)
{
	unsigned int	args[4]; 
	t_ind			ind;
	unsigned int	reg;
	unsigned int	reg2;
	int				adress;

	ft_init_args(map, car->position, args);
	reg = map[(car->position + 2) % 4096][0];
	reg2 = map[(car->position + 3) % 4096][0];
	ft_init_t_ind(map, car->position + 3, &ind);
	adress = (car->position + ind.data % IDX_MOD) % 4096;
	adress = (adress < 0 ? 4096 + adress : adress);
	if (ft_error_st(args, reg, reg2, car))
		return (1);
	if (args[1] == REG_CODE)
		car->registr[reg2 - 1]  = car->registr[reg - 1];
	else
		ft_rewrite_map(map, car, car->registr[reg - 1], adress);
	car->position += ft_move(args, "1100", 4) + 2;
	car->position %= 4096;
	return (1);
}
