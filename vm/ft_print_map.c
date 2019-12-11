/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:17:28 by bford             #+#    #+#             */
/*   Updated: 2019/12/10 11:17:47 by bford            ###   ########.fr       */
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
	return (1);
}

int		ft_print_line(unsigned char map[4096][4], int i)
{
	int	t;

	move(i + 2, 3);
	i *= 64;
	t = 0;
	while (t < 64 && ++t)
	{
		color_set(map[t - 1 + i][1] , NULL);
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
	printw(GRANICA);
	mvprintw(67, 0, GRANICA);
	i = 0;
	while (i < 68 && ++i)
		mvaddch(i - 1, 0, '*');
	i = 0;
	while (i < 68 && ++i)
		mvaddch(i - 1, 196, '*');
	i = 0;
	while (i < 68 && ++i)
		mvaddch(i - 1, 253, '*');
	color_set(1, NULL);
	attroff(A_BOLD);
	return (1);
}

int		ft_print_map(unsigned char map[4096][4])
{
	int y;

	y = 0;
	initscr();
	curs_set(0);
	start_color();
	ft_init_colors();
	refresh();
	WINDOW *win = newwin(68, 197, 0, 0);
	box(win, 0, 0);
	ft_print_contur();
	while (y < 64 && ++y)
		ft_print_line(map, y - 1);
	wrefresh(win);
	getch();
	endwin();
	return (1);
}
