/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_map_static.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:11:17 by kpsylock          #+#    #+#             */
/*   Updated: 2020/01/26 21:11:19 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_print_map.h"

int		vm_print_winner_v(t_player *player, t_cycle *cycle)
{
	while (player->next && player->num != cycle->winner_num)
		player = player->next;
	attron(A_BOLD);
	color_set(11, NULL);
	mvprintw(9, 199, "Processes : %-5d", cycle->cur_len);
	mvprintw(cycle->winner_y + 12 + 2, 199, "The winner is : ");
	mvprintw(cycle->winner_y + 12 + 4, 199, "Press any key to finish");
	color_set(player->num, NULL);
	mvprintw(cycle->winner_y + 12 + 2, 215, player->name);
	getch();
	endwin();
	return (1);
}

void	print_border(void)
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
