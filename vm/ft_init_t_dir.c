/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:58:28 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 18:33:25 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_init_t_dir(unsigned char map[MEM_SIZE][4],
int position, t_dir *dir)
{
	(*dir).bytes[0] = map[(position + 3) % MEM_SIZE][0];
	(*dir).bytes[1] = map[(position + 2) % MEM_SIZE][0];
	(*dir).bytes[2] = map[(position + 1) % MEM_SIZE][0];
	(*dir).bytes[3] = map[position % MEM_SIZE][0];
	mvprintw(56, 200, "bit 0 = %5u | orig = %5u %02x", (*dir).bytes[0], map[(position + 3) % MEM_SIZE][0], map[(position + 3) % MEM_SIZE][0]);
	mvprintw(57, 200, "bit 1 = %5u | orig = %5u %02x", (*dir).bytes[1], map[(position + 2) % MEM_SIZE][0], map[(position + 2) % MEM_SIZE][0]);
	mvprintw(58, 200, "bit 2 = %5u | orig = %5u %02x", (*dir).bytes[2], map[(position + 1) % MEM_SIZE][0], map[(position + 1) % MEM_SIZE][0]);
	mvprintw(59, 200, "bit 3 = %5u | orig = %5u %02x", (*dir).bytes[3], map[position % MEM_SIZE][0], map[position % MEM_SIZE][0]);
	mvprintw(60, 200, "RESULP DATA = *%u*", (*dir).data);
}
