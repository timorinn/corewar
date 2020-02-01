/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_t_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:58:28 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:23:05 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_dir	vm_init_t_dir(uint8_t map[MEM_SIZE][4],
	int position, uint8_t dir_size)
{
	t_dir dir;

	ft_bzero(&dir, sizeof(t_dir));
	if (dir_size == 4)
	{
		dir.bytes[0] = map[(position + 3) % MEM_SIZE][0];
		dir.bytes[1] = map[(position + 2) % MEM_SIZE][0];
		dir.bytes[2] = map[(position + 1) % MEM_SIZE][0];
		dir.bytes[3] = map[position % MEM_SIZE][0];
	}
	else
	{
		dir.bytes[0] = map[(position + 1) % MEM_SIZE][0];
		dir.bytes[1] = map[(position) % MEM_SIZE][0];
	}
	return (dir);
}
