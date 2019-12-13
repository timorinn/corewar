/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:25:36 by bford             #+#    #+#             */
/*   Updated: 2019/12/13 20:29:18 by bford            ###   ########.fr       */
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

int		ft_error_move(unsigned int args[4], int t_dir)
{
	int		i;
	int		move;

	i = 0;
	move = 0;
	while (i < 4)
	{
		if (args[i] == 1)
			move += 1;
		else if (args[i] == 2)
			move += t_dir;
		else if (args[i] == 3)
			move += 2;
		i++;
	}
	return (move);
}

int		ft_ld_error(unsigned int args[4], int reg, careta *car, int t_dir)
{

	if ((args[0] != 2 && args[0] != 3) || (args[1] != 1) || args[2] ||
	args[3] || reg == 0 || reg > 16)
	{
		car[0].position += ft_error_move(args, t_dir);
		return (1);
	}
	return (0);
}

int     ft_ld(unsigned char map[4096][4], careta *car, int v)
{
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

	
/*
    arg_type = (car[0].position == 4095 ? map[0][0] : map[car[0].position + 1][0]);
	args[0] = (arg_type >> 6) & 3;
	args[1] = (arg_type >> 4) & 3;
	args[2] = (arg_type >> 2) & 3;
	args[3] = arg_type & 3;

	if (!v)
		printf("car.num = %d | arg_type = %x | args %d %d %d %d\n", car[0].play_num, map[arg_type][0], args[0], args[1], args[2], args[3]);
	else
		mvprintw(70, 5, "car.num = %d | arg_type = %x | args %d %d %d %d\n", car[0].play_num, map[arg_type][0], args[0], args[1], args[2], args[3]);

	ind.bits[0] = (car[0].position + 3 > 4095 ? map[car[0].position + 3 - 4096][0] : map[car[0].position + 3][0]);
	ind.bits[1] = (car[0].position + 2 > 4095 ? map[car[0].position + 2 - 4096][0] : map[car[0].position + 2][0]);
	ind.data = args[0] == 3 ? ind.data % IDX_MOD : 2;
	dir.bits[0] = (car[0].position + ind.data + 3 > 4095 ? map[car[0].position + ind.data + 3 - 4096][0] : map[car[0].position + ind.data + 3][0]);
	dir.bits[1] = (car[0].position + ind.data + 2 > 4095 ? map[car[0].position + ind.data + 2 - 4096][0] : map[car[0].position + ind.data + 2][0]);
	dir.bits[2] = (car[0].position + ind.data + 1 > 4095 ? map[car[0].position + ind.data + 1 - 4096][0] : map[car[0].position + ind.data + 1][0]);
	dir.bits[3] = (car[0].position + ind.data > 4095 ? map[car[0].position + ind.data - 4096][0] : map[car[0].position + ind.data][0]);

	reg = (car[0].position + ind.data + 4 > 4095 ? map[car[0].position + ind.data + 4 - 4096][0] : map[car[0].position + ind.data + 4][0]);
	if (ft_ld_error(args, reg, car, 4))
		return (1);
	car[0].carry = (dir.data ? 0 : 1);
	car[0].registr[reg] = dir.data;
	car[0].position++;
	mvprintw(71, 5, "car.pos = %d\n", car[0].position);

	if (!v)
		printf("ind = %d | %02x %02x   ||   dirs = %d | %02x %02x %02x %02x\n", ind.data, ind.bits[0], ind.bits[1], dir.data, dir.bits[0], dir.bits[1], dir.bits[2], dir.bits[3]);
	else
		mvprintw(72, 0, "ind = %d | %02x %02x   ||   dirs = %d | %02x %02x %02x %02x\n", ind.data, ind.bits[0], ind.bits[1], dir.data, dir.bits[0], dir.bits[1], dir.bits[2], dir.bits[3]);
*/

	
/*		
	if (args[0] == 2)
	{
		printf("args[0] == %d\n", args[0]);
		dir.bits[3] = (car.position + 5 > 4095 ? map[car.position + 5 - 4095][0] : map[car.position + 5][0]);
		dir.bits[2] = (car.position + 4 > 4095 ? map[car.position + 4 - 4095][0] : map[car.position + 4][0]);
		dir.bits[1] = (car.position + 3 > 4095 ? map[car.position + 3 - 4095][0] : map[car.position + 3][0]);
		dir.bits[0] = (car.position + 2 > 4095 ? map[car.position + 2 - 4095][0] : map[car.position + 2][0]);  
		reg = car.position + 6 > 4095 ? map[car.position + 6 - 4095][0] : map[car.position + 6][0];
		car.registr[reg] = dir.data;
		printf("args[0] = %d |  reg[%d] = %d\n", dir.data, reg, car.registr[reg]);
		return (1);
	}
	else if (args[0] == 3)
	{
		ind.bits[1] = (car.position + 3 > 4095 ? map[car.position + 3 - 4095][0] : map[car.position + 3][0]);
		ind.bits[0] = (car.position + 2 > 4095 ? map[car.position + 2 - 4095][0] : map[car.position + 2][0]);
		args[0] = ind.data % IDX_MOD;
		dir.bits[3] = (car.position + args[0] > 4092 ? map[car.position + args[0] - 4092][0] : map[car.position + args[0] + 3][0]);
		dir.bits[2] = (car.position + args[0] > 4093 ? map[car.position + args[0] - 4093][0] : map[car.position + args[0] + 2][0]);
		dir.bits[1] = (car.position + args[0] > 4094 ? map[car.position + args[0] - 4094][0] : map[car.position + args[0] + 1][0]);
		dir.bits[0] = (car.position + args[0] > 4095 ? map[car.position + args[0] - 4095][0] : map[car.position + args[0]][0]);
		//printf("args[0] = %d |  reg[%d] = %d\n", dir.data, reg, car.registr[reg]);
	}
*/
	//printf("t_reg [0] = %d %x\n", args[0], args[0]);

	//printf("arg_type = %x | args %d %d %d %d\n", map[arg_type][0], args[0], args[1], args[2], args[3]);

	return (1);
}
