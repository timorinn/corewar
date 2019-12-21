/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:25:36 by bford             #+#    #+#             */
/*   Updated: 2019/12/19 16:14:13 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		ft_ld_error(unsigned int args[4], unsigned int reg,
t_cursor *car)
{
	if ((args[0] != DIR_CODE && args[0] != IND_CODE) || (args[1] != REG_CODE) || args[2] ||
	args[3] || reg < 1 || reg > REG_NUMBER)
	{
		car->position += 2 + ft_move(args, "1100", ft_dir_or_ind(args[0], 4));
		car->position %= MEM_SIZE;
		return (1);
	}
	return (0);
}

static int		ft_init_reg(unsigned char map[MEM_SIZE][4],
int position, int arg)
{
	int		dir_or_ind;

	dir_or_ind = ft_dir_or_ind(arg, 4);
	return (map[(position + dir_or_ind + 2) % MEM_SIZE][0]);
}

int				ft_ld(unsigned char map[MEM_SIZE][4], t_cursor *car)
{
	unsigned int	args[4];
	t_dir			dir;
	t_ind			ind;
	unsigned int	reg;

	ft_init_args(map, car->position, args);
	ft_init_t_ind(map, car->position + 2, &ind);
	ind.data = (args[0] == 3 ? ind.data % IDX_MOD : 2);
	ft_init_t_dir(map, car->position + ind.data, &dir);
	//reg = (car[0].position + ft_dir_or_ind(args[0], 4) + 2 > (MEM_SIZE - 1) ? map[car[0].position + ft_dir_or_ind(args[0], 4) + 2 - MEM_SIZE][0] : map[car[0].position + 2 + ft_dir_or_ind(args[0], 4)][0]);
	reg = ft_init_reg(map, car->position, args[0]) - 1;
	//mvprintw(52, 200, "reg = %d | data = %d | pos = %d | dir_or_ind = %d", reg, dir.data, car[0].position, ft_dir_or_ind(args[0], 4));
	//mvprintw(51, 200, "args %d %d %d %d", args[0], args[1], args[2], args[3]);
	if (ft_ld_error(args, reg, car))
		return (1);
	car->carry = (dir.data ? 0 : 1);
	car->registr[reg] = dir.data;
	car->position += ft_move(args, "1100", 4) + 2;
	car->position %= MEM_SIZE;
	return (1);
}
