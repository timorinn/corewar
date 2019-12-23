/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:17:28 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 21:25:46 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_init_colors(void)
{
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
	return (1);
}

void	ft_find_color(int position, t_cursor *car, int def)
{
	int	size;

	size = 0;
	while (size < car->size && car[size - 1].position != position)
		++size;
	if (car[size - 1].position == position)
		color_set(car[size - 1].play_num + 6, NULL);
	else
		color_set(def, NULL);
}

int		ft_print_line(unsigned char map[MEM_SIZE][4], int i, t_cursor *car)
{
	int	t;

	move(i + 2, 3);
	i *= 64;
	t = 0;
	while (t < 64 && ++t)
	{
		ft_find_color(t - 1 + i, car, map[t - 1 + i][1]);
		if (map[t - 1 + i][1] == 1)
			attron(A_BOLD);
		printw("%02x", map[t - 1 + i][0]);
		attroff(A_BOLD);
		color_set(1, NULL);
		printw(" ");
	}
	color_set(1, NULL);
	return (1);
}

int		ft_print_contur(void)
{
	int	i;

	color_set(2, NULL);
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
	color_set(1, NULL);
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

int		ft_print_backside(int *cycle, t_player *player, t_cursor *car)
{
	int		y;

	y = 11;
	attron(A_BOLD);
	color_set(11, NULL);
	mvprintw(7, 199, "Cycle : %d\n", (*cycle)++);
	mvprintw(9, 199, "Processes : %d\n", car[0].size);
	while (player)
	{
		color_set(11, NULL);
		mvprintw(y, 199, "Player -%d :", (y - 11) / 4 + 1);
		mvprintw(y + 1, 201, "Last live :               %7d", 0);
		mvprintw(y + 2, 201, "Lives in current period : %7d", 0);
		color_set(player->num + 2, NULL);
		mvprintw(y, 211, "%.41s", player->name);
		y += 4;
		player = player->next;
	}
	color_set(11, NULL);
	mvprintw(y, 199, "Live breakdown for current period :");
	mvprintw(y + 3, 199, "Live breakdown for last period :");
	mvprintw(y + 6, 199, "CYCLE_TO_DIE : %d", CYCLE_TO_DIE);
	mvprintw(y + 8, 199, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvprintw(y + 10, 199, "NBR_LIVE : %d", NBR_LIVE);
	mvprintw(y + 12, 199, "MAX_CHECKS : %d", MAX_CHECKS);
	color_set(1, NULL);
	mvprintw(y + 1, 199, "[");
	mvprintw(y + 4, 199, "[");
	mvprintw(y + 1, 250, "]");
	mvprintw(y + 4, 250, "]");
	attroff(A_BOLD);
	ft_print_breakdown(y);
	return (1);
}

int		ft_print_params(t_cursor *car)
{
	int		i = car[0].size - 1;
	int		y = 70;
	int		reg;

	color_set(11, NULL);
	while (i >= 0)
	{
		mvprintw(y, 10, "Car #%d   | pl_num: %d | position: %4d | oper: %02x | cd: %3d | carry: %d | size: %d",
		car[i].num ,car[i].play_num, car[i].position, car[i].operation, car[i].cooldown, car[i].carry, car[i].size);
		reg = 0;
		while (reg < 8 && ++reg)
		{
			mvprintw(y + 1, 16 + (reg - 1) * 21, "r%02d: %10d   |   ", reg - 1, car[i].registr[reg - 1]);
			mvprintw(y + 2, 16 + (reg - 1) * 21, "r%02d: %10d   |   ", reg - 1 + 8, car[i].registr[reg - 1 + 8]);
		}
		i--;
		y += 4;
	}

	/*
	mvprintw(90 + 1, 16, "FREE PLACE!");
	*/

	return (1);
}

int		ft_print_map(unsigned char map[MEM_SIZE][4], t_cursor *car, t_player *player)
{
	int y;
	int cycle = 0;

	initscr();
	curs_set(0);
	start_color();
	ft_init_colors();
	refresh();
	noecho();
	//WINDOW *win = newwin(68, 197, 0, 0);
	//box(win, 0, 0);

	char c = 's';
	while (c != 'q')
	{
		ft_print_backside(&cycle, player, car);
		ft_print_params(car);
	
		ft_do_cycle(map, &car, cycle);

		ft_print_contur();
		y = 0;
		while (y < 64 && ++y)
			ft_print_line(map, y - 1, car);

		//wrefresh(win);
//		refresh();
		c = getch();
//		clear();
	}
	endwin();
	return (1);
}
