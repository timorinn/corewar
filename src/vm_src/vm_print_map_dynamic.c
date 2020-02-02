/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_map_dynamic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:11:26 by kpsylock          #+#    #+#             */
/*   Updated: 2020/02/02 13:13:46 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_print_map.h"

inline int	vm_print_line(uint8_t map[MEM_SIZE][4], int i)
{
	int	t;

	move(i + 2, 3);
	i *= 64;
	t = 0;
	while (t < 64)
	{
		vm_find_color(map, t + i);
		if (map[t + i][1] == 5)
			attron(A_BOLD);
		printw("%02x", map[t + i][0]);
		attroff(A_BOLD);
		color_set(5, NULL);
		printw(" ");
		++t;
	}
	color_set(5, NULL);
	return (1);
}

int	print_players(t_player *player, t_cycle *cycle, int y)
{
	while (player)
	{
		color_set(11, NULL);
		mvprintw(y, 199, "Player -%d :", (y - 11) / 4 + 1);
		mvprintw(y + 1, 201, "Last live :               %7d",
				cycle->last_live[player->num]);
		mvprintw(y + 2, 201, "Lives in current period : %7d",
				cycle->lives_in_current_period[player->num]);
		color_set(player->num, NULL);
		mvprintw(y, 211, "%.41s", player->name);
		y += 4;
		player = player->next;
	}
	return (y);
}

inline int	vm_print_backside(t_cycle *cycle, t_player *player)
{
	int		y;

	y = 11;
	attron(A_BOLD);
	color_set(11, NULL);
	mvprintw(7, 199, "Cycle : %d", cycle->cycle_num++);
	mvprintw(9, 199, "Processes : %-5d", cycle->cur_len);
	y = print_players(player, cycle, y);
	color_set(11, NULL);
	mvprintw(y, 199, "Live breakdown for current period :");
	mvprintw(y + 3, 199, "Live breakdown for last period :");
	mvprintw(y + 6, 199, "CYCLE_TO_DIE : %-5d", cycle->cycles_to_die);
	mvprintw(y + 8, 199, "CYCLE_DELTA : %-2d", CYCLE_DELTA);
	mvprintw(y + 10, 199, "NBR_LIVE : %-2d", NBR_LIVE);
	mvprintw(y + 12, 199, "MAX_CHECKS : %-2d", MAX_CHECKS);
	color_set(5, NULL);
	mvprintw(y + 1, 199, "[");
	mvprintw(y + 4, 199, "[");
	mvprintw(y + 1, 250, "]");
	mvprintw(y + 4, 250, "]");
	attroff(A_BOLD);
	vm_print_breakdown(y);
	cycle->winner_y = y;
	return (y + 12);
}
