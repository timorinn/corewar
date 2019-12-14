/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:25:36 by bford             #+#    #+#             */
/*   Updated: 2019/12/14 16:14:58 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

typedef union	u_dir
{
	uint8_t bits[4];
	uint32_t data;
}				t_dir;

typedef union	u_ind
{
	uint8_t bits[2];
	uint16_t data;
}				t_ind;

int		ft_move(unsigned int args[4], int valid)
{
	int		i;
	int		move;

	i = 0;
	move = 0;
	while (i < 4)
	{
		if (valid & (10 * (i + 1)))
		{
			if (args[i] == 1)
				move += 1;
			else if (args[i] == 2)
				move += valid % 10;
			else if (args[i] == 3)
				move += 2;
		}
		i++;
	}
	return (move);
}

int		ft_ld_error(unsigned int args[4], int reg, careta *car, int valid)
{

	if ((args[0] != 2 && args[0] != 3) || (args[1] != 1) || args[2] ||
	args[3] || reg == 0 || reg > 16)
	{
		car[0].position += ft_move(args, valid) + 2;
		car[0].position -= (car[0].position > 4095 ? 4096 : 0);
		return (1);
	}
	return (0);
}

int     ft_ld(unsigned char map[4096][4], careta *car, int v)
{
	v+=0;

	int				arg_type;
	unsigned int	args[4];
	t_dir			dir;
	t_ind			ind;
	unsigned int	reg;
	
    arg_type = (car[0].position == 4095 ? map[0][0] : map[car[0].position + 1][0]);
	args[0] = (arg_type >> 6) & 3;
	args[1] = (arg_type >> 4) & 3;
	args[2] = (arg_type >> 2) & 3;
	args[3] = arg_type & 3;
	ind.bits[0] = (car[0].position + 3 > 4095 ? map[car[0].position + 3 - 4096][0] : map[car[0].position + 3][0]);
	ind.bits[1] = (car[0].position + 2 > 4095 ? map[car[0].position + 2 - 4096][0] : map[car[0].position + 2][0]);
	ind.data = args[0] == 3 ? ind.data % IDX_MOD : 2;
	dir.bits[0] = (car[0].position + ind.data + 3 > 4095 ? map[car[0].position + ind.data + 3 - 4096][0] : map[car[0].position + ind.data + 3][0]);
	dir.bits[1] = (car[0].position + ind.data + 2 > 4095 ? map[car[0].position + ind.data + 2 - 4096][0] : map[car[0].position + ind.data + 2][0]);
	dir.bits[2] = (car[0].position + ind.data + 1 > 4095 ? map[car[0].position + ind.data + 1 - 4096][0] : map[car[0].position + ind.data + 1][0]);
	dir.bits[3] = (car[0].position + ind.data > 4095 ? map[car[0].position + ind.data - 4096][0] : map[car[0].position + ind.data][0]);

	reg = (car[0].position + ind.data + 4 > 4095 ? map[car[0].position + ind.data + 4 - 4096][0] : map[car[0].position + ind.data + 4][0]);
	if (ft_ld_error(args, reg, car, 11004))
		return (1);
	car[0].carry = (dir.data ? 0 : 1);
	car[0].registr[reg] = dir.data;
	car[0].position += ft_move(args, 1100) + 2;
	car[0].position -= (car[0].position > 4095 ? 4096 : 0);
	return (1);
}
