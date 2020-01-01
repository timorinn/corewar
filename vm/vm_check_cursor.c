/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:43:38 by bford             #+#    #+#             */
/*   Updated: 2020/01/01 03:43:27 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_check_players(t_cursor *cur, t_cycle *cycle)
{
	int		num_for_check;
	int		i;

	num_for_check = cur[0].play_num;
	i = 1;
	while (i < cycle->cur_len)
	{
		if (cur[i].play_num != num_for_check)
			return (0);
		i++;
	}
	return (1);
}

int		vm_delete_one_cursor(t_cursor **cur, int i, int size)
{
	t_cursor	*new;

	if (!(new = malloc(sizeof(t_cursor) * size)))
		return (0);
	ft_memmove(new, *cur, i * sizeof(t_cursor));
	ft_memmove(new + i, *cur + i + 1, (size - i) * sizeof(t_cursor));
	free(*cur);
	*cur = new;
	return (1);
}

int		vm_check_cursor(uint8_t map[MEM_SIZE][4],
						t_cursor **cur, t_cycle *cycle)
{
	map+=0;

	// ГДЕ ТО ТУТ ОШИБКА
	// КУРСОРЫ УДАЛЯЮТСЯ НЕВЕРНО

	int		i;

	if ((cycle->cycle_num == cycle->waiting_die + 1) ||
	cycle->cycles_to_die <= 0)
	{
		i = 0;
		/*
		cycle->cycles_to_die -= (cycle->lives_in_current_period_all >= NBR_LIVE ? CYCLE_DELTA : 0);
		cycle->lives_in_current_period_all = 0;
		*/
		while (i < cycle->cur_len)
		{
			if ((*cur)[i].live + cycle->cycles_to_die < cycle->cycle_num - 1552)
			{
				if (!vm_delete_one_cursor(cur, i, --cycle->cur_len))
					return (0);
				continue; // ?
			}
			i++;
		}
		cycle->cycles_to_die -= (cycle->lives_in_current_period_all >= NBR_LIVE ? CYCLE_DELTA : 0);
		cycle->waiting_die += cycle->cycles_to_die;
		printf("WAITING DIE = %d\n", cycle->waiting_die);
		cycle->lives_in_current_period_all = 0;
		
		ft_bzero(cycle->lives_in_current_period, sizeof(int) * MAX_PLAYERS);
	}
	return (1);
}
