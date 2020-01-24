/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:43:38 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:51:02 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_check_cursor(uint8_t map[MEM_SIZE][4],
						t_cursor **cur, t_cycle *cycle)
{
	t_cursor	*copy;
	t_cursor	*for_del;

	if (cycle->cycles_to_die <= 0)
		return (1);
	if (cycle->cycle_num == cycle->waiting_die/* + 1 */)
	{
		copy = *cur;
//		if (*cur == NULL) // ЭТИ СТОКИ ДОЛЖНЫ БЫТЬ ЛИШНИМИ
//			return (1); //
		while (copy)
		{
			if (copy->next &&
			copy->next->live + cycle->cycles_to_die <= cycle->cycle_num)
			{
				cycle->cur_len--;
				for_del = copy->next;
				map[for_del->position][2] -= 1;
				copy->next = copy->next->next;
				free(for_del);
				for_del = NULL;
			}
			else
				copy = copy->next;
		}
		// <= or < ?? //
		if ((*cur)->live + cycle->cycles_to_die <= cycle->cycle_num)
		{
			cycle->cur_len--;
			copy = (*cur)->next;
			map[(*cur)->position][2] -= 1;
			free(*cur);
			if (!(*cur = copy))
				return (1);
		}
		cycle->checks++;
		if (cycle->lives_in_current_period_all >= NBR_LIVE ||
		cycle->checks == MAX_CHECKS)
		{
			cycle->cycles_to_die -= CYCLE_DELTA;
			if (cycle->log)
				ft_printf("Cycle to die is now %d\n", cycle->cycles_to_die);
			cycle->checks = 0;
		}
		cycle->waiting_die += cycle->cycles_to_die;
		cycle->lives_in_current_period_all = 0;
		ft_bzero(cycle->lives_in_current_period, sizeof(int) * MAX_PLAYERS);
	}
	return (0);
}
