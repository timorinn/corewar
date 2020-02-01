/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:17:28 by bford             #+#    #+#             */
/*   Updated: 2020/01/29 17:10:16 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_print_map.h"

inline static char	visu_pause(void)
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

	c = visu_pause();
	while (c != 'q')
	{
		vm_print_backside(cycle, player);
		vm_do_cycle(map, cur, cycle);
		y = 0;
		while (y < 64 && ++y)
			vm_print_line(map, y - 1);
		refresh();
        if (vm_check_cursor(map, cur, cycle))
        {
            vm_print_winner_v(player, cycle);
            visu_pause();
            return ;
        }
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
