/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_rewrite_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 12:48:48 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 12:53:52 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_rewrite_map(uint8_t map[MEM_SIZE][4],
t_cursor *cur, unsigned int reg, int adress)
{
	map[(adress + 3) % MEM_SIZE][0] = (uint8_t)reg;
	map[(adress + 3) % MEM_SIZE][1] = cur->play_num;
	map[(adress + 2) % MEM_SIZE][0] = (uint8_t)(reg >> 8);
	map[(adress + 2) % MEM_SIZE][1] = cur->play_num;
	map[(adress + 1) % MEM_SIZE][0] = (uint8_t)(reg >> 16);
	map[(adress + 1) % MEM_SIZE][1] = cur->play_num;
	map[adress % MEM_SIZE][0] = (uint8_t)(reg >> 24);
	map[adress % MEM_SIZE][1] = cur->play_num;
}
