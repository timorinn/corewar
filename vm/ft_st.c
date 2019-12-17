/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stasyan <stasyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:49:21 by stasyan           #+#    #+#             */
/*   Updated: 2019/12/17 12:15:43 by stasyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_rewrite_map(unsigned char map[4096][4], careta *car, unsigned int reg, int adress)
{
	map[adress + 3 > 4095 ? adress + 3 - 4096 : adress + 3][0] = reg;
	map[adress + 3 > 4095 ? adress + 3 - 4096 : adress + 3][1] = car[0].play_num + 2;
	map[adress + 2 > 4095 ? adress + 2 - 4096 : adress + 2][0] = reg >> 8;
	map[adress + 2 > 4095 ? adress + 2 - 4096 : adress + 2][1] = car[0].play_num + 2;
	map[adress + 1 > 4095 ? adress + 1 - 4096 : adress + 1][0] = reg >> 16;
	map[adress + 1 > 4095 ? adress + 1 - 4096 : adress + 1][1] = car[0].play_num + 2;
	map[adress > 4095 ? adress - 4096 : adress][0] = reg >> 24;
	map[adress > 4095 ? adress - 4096 : adress][1] = car[0].play_num + 2;
	return (1);
}

int		ft_error_st(unsigned int args[4], int reg, int reg2, careta *car)
{
	if (args[0] != REG_CODE || (args[1] != REG_CODE && args[1] != IND_CODE) ||
	reg < 1 || reg > 16 || (args[1] == REG_CODE && (reg2 < 1 || reg2 > 16)))
	{
		car[0].position += ft_move(args, "1100", 4) + 2;
		car[0].position -= (car[0].position > 4095 ? 4096 : 0);
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

	ft_init_args(map, car[0].position, args);
	reg = car[0].position + 2 > 4095 ? map[car[0].position + 2 - 4096][0] : map[car[0].position + 2][0];
	reg2 = car[0].position + 3 > 4095 ? map[car[0].position + 3 - 4096][0] : map[car[0].position + 3][0];
	ft_init_t_ind(map, car[0].position + 3, &ind);
	adress = car[0].position + ind.data % IDX_MOD > 4095 ? car[0].position + ind.data % IDX_MOD - 4096 :
	car[0].position + ind.data % IDX_MOD;
	if (ft_error_st(args, reg, reg2, car))
		return (1);
	if (args[1] == REG_CODE)
		car[0].registr[reg2 - 1]  = car[0].registr[reg - 1];
	else
	{
		ft_rewrite_map(map, car, car[0].registr[reg - 1], adress);
		//map[adress][0] = car[0].registr[reg - 1];
		//map[adress][1] = car[0].play_num + 2;
	}
	car[0].position += ft_move(args, "1100", 4) + 2;
	car[0].position -= (car[0].position > 4095 ? 4096 : 0);
	return (1);
}
