/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_map_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:11:03 by kpsylock          #+#    #+#             */
/*   Updated: 2020/01/26 21:11:06 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_print_map.h"

void	vm_init_colors(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, 241, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(10, COLOR_BLACK, 241);
	init_pair(11, COLOR_WHITE, COLOR_BLACK);
}

void	vm_find_color(uint8_t map[MEM_SIZE][4], int position)
{
	if (map[position][2])
		color_set(map[position][1] + 5, NULL);
	else
		color_set(map[position][1], NULL);
}
