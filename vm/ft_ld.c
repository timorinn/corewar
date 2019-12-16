/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stasyan <stasyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:25:36 by bford             #+#    #+#             */
/*   Updated: 2019/12/16 11:53:57 by stasyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_ld_error(unsigned int args[4], unsigned int reg, careta *car, char *valid)
{
	if ((args[0] != 2 && args[0] != 3) || (args[1] != 1) || args[2] ||
	args[3] || reg < 1 || reg > 16)
	{
		car[0].position += 2 + ft_move(args, valid, ft_dir_or_ind(args[0], 4));
		car[0].position -= (car[0].position > 4095 ? 4096 : 0);
		return (1);
	}
	return (0);
}

int				ft_init_reg(unsigned char map[4096][4],
int position, int arg)
{
	int		dir_or_ind;

	dir_or_ind = ft_dir_or_ind(arg, 4);
	return (position + dir_or_ind + 2 > 4095 ?
	map[position + dir_or_ind + 2 - 4096][0] :
	map[position + dir_or_ind + 2][0]);
}

void ft_ch(unsigned char map[4096][4],
int position, unsigned char ch[4])
{
	int i = 0;
	int i2 = 3;
	while (i < 4)
	{
		ch[i] = map[position + i2][0];
		i2--;
		i++;
	}
}


int				ft_ld(unsigned char map[4096][4], careta *car)
{
	unsigned int	args[4];
	t_dir			dir;
	t_ind			ind;
	unsigned int	reg;

	unsigned int check;
	unsigned char ch[4];

	ft_init_args(map, car[0].position, args);
	ft_init_t_ind(map, car[0].position + 2, &ind);
	ind.data = args[0] == 3 ? ind.data % IDX_MOD : 2;
	ft_init_t_dir(map, car[0].position + ind.data, &dir);
	ft_ch(map, car[0].position + ind.data, ch);
	ft_memcpy(&check, ch, 4);
	mvprintw(63, 200, "map[pos] = %u :: check = %u", map[car[0].position + ind.data][0], check);
	//reg = (car[0].position + ft_dir_or_ind(args[0], 4) + 2 > 4095 ? map[car[0].position + ft_dir_or_ind(args[0], 4) + 2 - 4096][0] : map[car[0].position + 2 + ft_dir_or_ind(args[0], 4)][0]);
	reg = ft_init_reg(map, car[0].position, args[0]) - 1;
	//mvprintw(52, 200, "reg = %d | data = %d | pos = %d | dir_or_ind = %d", reg, dir.data, car[0].position, ft_dir_or_ind(args[0], 4));
	//mvprintw(51, 200, "args %d %d %d %d", args[0], args[1], args[2], args[3]);
	if (ft_ld_error(args, reg, car, "1100"))
		return (1);
	mvprintw(54, 200, "DATA = %u | bits %u %u %u %u", dir.data, dir.bits[0], dir.bits[1], dir.bits[2], dir.bits[3]);
	car[0].carry = (dir.data ? 0 : 1);
	car[0].registr[reg] = dir.data;
	car[0].position += ft_move(args, "1100", 4) + 2;
	car[0].position -= (car[0].position > 4095 ? 4096 : 0);
	return (1);
}
