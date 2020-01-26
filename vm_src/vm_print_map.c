/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:17:28 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 12:43:42 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_print_winner_v(t_player *player, t_cycle *cycle)
{
	while (player->next && player->num != cycle->winner_num)
		player = player->next;
	attron(A_BOLD);
	color_set(11, NULL);
	mvprintw(9, 199, "Processes : %-5d", cycle->cur_len);
	//mvprintw(7, 199, "Cycle : %d", cycle->cycle_num);
	// ??? А НАДО ЛИ? МБ ОШИБКА В ВЫЧИСЛЕНИЯХ ЦИКЛОВ?
	mvprintw(cycle->winner_y + 12 + 2, 199, "The winner is : ");
	mvprintw(cycle->winner_y + 12 + 4, 199, "Press any key to finish");
	color_set(player->num, NULL);
	mvprintw(cycle->winner_y + 12 + 2, 215, player->name);
	getch();
	endwin();
	return (1);
}

inline static void		vm_init_colors(void)
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

int		vm_print_line(uint8_t map[MEM_SIZE][4], int i)
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

inline static void	print_border(void)
{
	mvprintw(0, 0, "**********************************************************\
******************************************************************************\
******************************************************************************\
****************************************\n");
	mvprintw(67, 0, "*********************************************************\
******************************************************************************\
******************************************************************************\
*****************************************\n");
}

int		vm_print_contur(void)
{
	int	i;

	color_set(10, NULL);
	attron(A_BOLD);
	print_border();
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

int		vm_print_breakdown(int y)
{
	color_set(11, NULL);
	mvprintw(y + 1, 200, "------------THERE-IS-NO-BREAKDOWN-----------------");
	mvprintw(y + 4, 200, "-----------BREAKDOWN-IS-USELESS-;)----------------");
	return (1);
}

int		vm_print_backside(t_cycle *cycle, t_player *player)
{
	int		y;

	y = 11;
	attron(A_BOLD);
	color_set(11, NULL);
	mvprintw(7, 199, "Cycle : %d", ++cycle->cycle_num);
	mvprintw(9, 199, "Processes : %-5d", cycle->cur_len);
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

inline static char		visu_pause(void)
{
	char c;

	c = 0;
	color_set(11, NULL);
	attron(A_BOLD);
	mvprintw(3, 199, "**  PAUSE  **");
	while (true)
	{
		if (c == 'q' || c == ' ')
		{
			mvprintw(3, 199, "** RUNNING **");
			color_set(10, NULL);
			attroff(A_BOLD);
			return (c);
		}
		c = 0;
		c = getch();
	}
}

inline static void	visu_main_cycle(uint8_t map[MEM_SIZE][4], t_cycle *cycle,
		t_player *player, t_cursor **cur)
{
	int		y;
	char	c;

	c = 0;
	c = visu_pause();
	while (c != 'q')
	{
		vm_print_backside(cycle, player);
		vm_do_cycle(map, cur, cycle); // мб надо поставить перед проверкой курсоров
		if (vm_check_cursor(map, cur, cycle))
		{
			vm_print_winner_v(player, cycle);
			visu_pause();
			return ;
		}
		y = 0;
		while (y < 64 && ++y)
			vm_print_line(map, y - 1);
		refresh();
		c = getch();
		if (c == ' ' || cycle->cycle_num == cycle->dump)
			c = visu_pause();
	}
	endwin();
}

void				vm_print_map(uint8_t map[MEM_SIZE][4], t_cursor **cur,
		t_player *player, t_cycle *cycle)
{
	WINDOW	*w;
	int		y;

	cbreak();
	w = initscr();
	nodelay(w, TRUE);
	curs_set(0);
	start_color();
	vm_init_colors();
	refresh();
	noecho();
	vm_print_contur();
	vm_print_backside(cycle, player);
	y = 0;
	while (y < 64 && ++y)
		vm_print_line(map, y - 1);
	visu_main_cycle(map, cycle, player, cur);
}
