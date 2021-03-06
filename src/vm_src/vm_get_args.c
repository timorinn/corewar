/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:02:23 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:39:33 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	get_reg(uint8_t map[MEM_SIZE][4], t_cursor *car,
		t_args *args, int arg_num)
{
	args->nums[arg_num] = map[(car->position + args->offset) % MEM_SIZE][0];
	args->offset += 1;
}

static void	get_dir(uint8_t map[MEM_SIZE][4], t_cursor *car,
		t_args *args, int arg_num)
{
	t_dir	dir;

	dir = vm_init_t_dir(map, (car->position + args->offset) % MEM_SIZE,
			args->dir_size);
	args->nums[arg_num] = dir.data;
	args->offset += args->dir_size;
}

static void	get_ind(uint8_t map[MEM_SIZE][4], t_cursor *car,
		t_args *args, int arg_num)
{
	t_ind	ind;

	vm_init_t_ind(map, (car->position + args->offset) % MEM_SIZE, &ind);
	args->nums[arg_num] = ind.data;
	args->offset += IND_SIZE;
}

int			vm_get_args(uint8_t map[MEM_SIZE][4], t_cursor *car, t_args *args)
{
	int		i;

	vm_init_args(map, car->position, args->types);
	args->offset = 2;
	i = 0;
	while (i < 3)
	{
		if (args->types[i] == REG_CODE)
			get_reg(map, car, args, i);
		else if (args->types[i] == IND_CODE)
			get_ind(map, car, args, i);
		else if (args->types[i] == DIR_CODE && args->dir_size == 4)
			get_dir(map, car, args, i);
		else if (args->types[i] == DIR_CODE && args->dir_size == 2)
			get_ind(map, car, args, i);
		i++;
	}
	return (true);
}
