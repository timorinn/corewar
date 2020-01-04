/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:17:28 by bford             #+#    #+#             */
/*   Updated: 2020/01/04 22:02:06 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_print_winner_v(t_player *player, t_cycle *cycle, int winner_y)
{
	while (player->num != cycle->winner_num)
		player = player->next;
	attron(A_BOLD);
	color_set(11, NULL);
	mvprintw(winner_y + 2, 199, "The winner is : ");
	mvprintw(winner_y + 4, 199, "Press any key to finish");
	color_set(player->num, NULL);
	mvprintw(winner_y + 2, 2015, player->name);
	getch();
	return (1);
}

int		ft_init_colors(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5 , 241, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(10, COLOR_BLACK, 241);
	init_pair(11, COLOR_WHITE, COLOR_BLACK);
	/*
	init_pair(1, 241, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, 241);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_GREEN);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_RED);
	init_pair(10, COLOR_BLACK, COLOR_CYAN);
	init_pair(11, COLOR_WHITE, COLOR_BLACK);
	*/
	return (1);
}

/*
void	ft_find_color(int position, t_cursor *cur, int def, int cur_len)
{
	
	int	size;

	size = 0;
	
	while (size < cur_len && cur[size].position != position)
		++size;
	if (size == cur_len)
		color_set(def, NULL);
	else
		color_set(cur[size].play_num + 6, NULL);

}
*/

void	ft_find_color(uint8_t map[MEM_SIZE][4], int position)
{
	if (map[position][2])
		color_set(map[position][1] + 5, NULL);
	else
		color_set(map[position][1], NULL);
		//color_set(5, NULL);
}

int		ft_print_line(uint8_t map[MEM_SIZE][4], int i, t_cursor *car,
						t_cycle *cycle)
{
	cycle+=0;car+=0;

	int	t;

	move(i + 2, 3);
	i *= 64;
	t = 0;
	while (t < 64)
	{
		//ft_find_color(t + i, car, map[t + i][1], cycle->cur_len);
		ft_find_color(map, t + i);
		if (map[t + i][1] == 5)
			attron(A_BOLD);
		printw("%02x", map[t + i][0]);
		attroff(A_BOLD);

		//color_set(1, NULL);
		color_set(5, NULL);
		printw(" ");
		++t;
	}
	// color_set(0, NULL);
	color_set(5, NULL);
	return (1);
}

int		ft_print_contur(void)
{
	int	i;

	// color_set(2, NULL);
	color_set(10, NULL);
	attron(A_BOLD);
	mvprintw(0, 0, GRANICA);
	mvprintw(67, 0, GRANICA);
	i = 0;
	while (i < 68 && ++i)
	{
		mvaddch(i - 1, 0, '*');
		mvaddch(i - 1, 196, '*');
		mvaddch(i - 1, 253, '*');
	}
	color_set(11, NULL);
	attroff(A_BOLD);
	return (1);
}

int		ft_print_breakdown(int y)
{
	color_set(11, NULL);
	mvprintw(y + 1, 200, "--------------------------------------------------");
	mvprintw(y + 4, 200, "--------------------------------------------------");
	return (1);
}

int		ft_print_backside(t_cycle *cycle, t_player *player, t_cursor *car)
{
	car+=0;

	int		y;

	y = 11;
	attron(A_BOLD);
	color_set(11, NULL);
	mvprintw(7, 199, "Cycle : %d", cycle->cycle_num++);
	mvprintw(9, 199, "Processes : %d", cycle->cur_len);
	while (player)
	{
		color_set(11, NULL);
		mvprintw(y, 199, "Player -%d :", (y - 11) / 4 + 1);
		mvprintw(y + 1, 201, "Last live :               %7d", cycle->last_live[player->num]);
		mvprintw(y + 2, 201, "Lives in current period : %7d", cycle->lives_in_current_period[player->num]);
		color_set(player->num, NULL);
		mvprintw(y, 211, "%.41s", player->name);
		y += 4;
		player = player->next;

	}
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
	ft_print_breakdown(y);
	return (y + 12);
}

int		ft_print_params(t_cursor *car, int cur_len)
{
	int		i;
	int		y;
	int		reg;

	color_set(11, NULL);
	y = 70;
	i = cur_len - 1;
	while (i >= 0)
	{
		if (car[i].play_num == 2) // delete esli cho
		{
			mvprintw(y, 10, "Car #%3d   | pl_num: %d | position: %4d | oper: %02x | cd: %3d | carry: %d | live: %5d",
			car[i].num ,car[i].play_num, car[i].position, car[i].operation, car[i].cooldown, car[i].carry, car[i].live);
			reg = 0;
			while (reg < 8 && ++reg)
			{
				mvprintw(y + 1, 16 + (reg - 1) * 21, "r%02d: %10d   |   ", reg, car[i].registr[reg]);
				mvprintw(y + 2, 16 + (reg - 1) * 21, "r%02d: %10d   |   ", reg + 8, car[i].registr[reg + 8]);
			}
			y += 4;
		}
		i--;
	}

	/*
	mvprintw(90 + 1, 16, "FREE PLACE!");
	*/

	return (y);
}

int			ft_print_map(uint8_t map[MEM_SIZE][4], t_cursor **cur,
						t_player *player, t_cycle *cycle)
{
	int y;
	int	winner_y;

	initscr();
	curs_set(0);
	start_color();
	ft_init_colors();
	refresh();
	noecho();
	ft_print_contur();

	char c = 's';
	while (c != 'q')
	{
		winner_y = ft_print_backside(cycle, player, *cur);
		ft_print_params(*cur, cycle->cur_len);
		if (vm_check_cursor(map, cur, cycle)) // new
			return (vm_print_winner_v(player, cycle, winner_y));
		ft_do_cycle(map, cur, cycle);
		y = 0;
		while (y < 64 && ++y)
			ft_print_line(map, y - 1, *cur, cycle);
		refresh();
		if (cycle->cycle_num >= cycle->dump)
			//break;
			c = getch();
	}
	endwin();
	return (1);
}
