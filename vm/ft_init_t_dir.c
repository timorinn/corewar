/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:58:28 by bford             #+#    #+#             */
/*   Updated: 2019/12/14 23:27:28 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_init_t_dir(unsigned char map[4096][4],
int position, t_dir *dir)
{
	(*dir).bits[0] = (position + 3 > 4095 ?
	map[position + 3 - 4096][0] : map[position + 3][0]);
	mvprintw(56, 200, "bit 0 = %5u | orig = %5u %02x", (*dir).bits[0], map[position + 3][0], map[position + 3][0]);
	(*dir).bits[1] = (position + 2 > 4095 ?
	map[position + 2 - 4096][0] : map[position + 2][0]);
	mvprintw(57, 200, "bit 1 = %5u | orig = %5u %02x", (*dir).bits[1], map[position + 2][0], map[position + 2][0]);
	(*dir).bits[2] = (position + 1 > 4095 ?
	map[position + 1 - 4096][0] : map[position + 1][0]);
	mvprintw(58, 200, "bit 2 = %5u | orig = %5u %02x", (*dir).bits[2], map[position + 1][0], map[position + 1][0]);
	(*dir).bits[3] = (position > 4095 ?
	map[position - 4096][0] : map[position][0]);
	mvprintw(59, 200, "bit 3 = %5u | orig = %5u %02x", (*dir).bits[3], map[position + 0][0], map[position + 0][0]);
	mvprintw(60, 200, "RESULP DATA = *%u*", (*dir).data);
}
