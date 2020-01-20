/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:43:38 by bford             #+#    #+#             */
/*   Updated: 2020/01/20 17:59:08 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
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
*/

/*
int		vm_delete_one_cursor(uint8_t map[MEM_SIZE][4], t_cursor **cur,
							int i, int size)
{
	t_cursor	*new;

	if (!(new = malloc(sizeof(t_cursor) * size)))
		return (0);
	map[(*cur)[i].position][2] = 0;
	ft_memmove(new, *cur, i * sizeof(t_cursor));
	ft_memmove(new + i, *cur + i + 1, (size - i) * sizeof(t_cursor));
	free(*cur);
	*cur = new;
	return (1);
}
*/

// int		vm_check_cursor(uint8_t map[MEM_SIZE][4],
// 						t_cursor **cur, t_cycle *cycle)
// {
// 	int		i;

// 	if (cycle->cycle_num == cycle->waiting_die + 1)
// 	{
// 		i = 0;
// 		///*
// 		//cycle->cycles_to_die -= (cycle->lives_in_current_period_all >= NBR_LIVE ? CYCLE_DELTA : 0);
// 		//cycle->lives_in_current_period_all = 0;
// 		//*/
// 		while (i < cycle->cur_len)
// 		{
// 			if ((*cur)[i].live + cycle->cycles_to_die < cycle->cycle_num)
// 			{
// 				if (!vm_delete_one_cursor(map, cur, i, --cycle->cur_len))
// 					return (-1);
// 				continue; // ?
// 			}
// 			i++;
// 		}
// 		if (cycle->lives_in_current_period_all >= NBR_LIVE ||
// 		cycle->checks == MAX_CHECKS)
// 		{
// 			cycle->cycles_to_die -= CYCLE_DELTA;
// 			cycle->checks = 0;
// 		}
// 		else
// 			cycle->checks++;

// 		//cycle->cycles_to_die -= (cycle->lives_in_current_period_all >= NBR_LIVE ? CYCLE_DELTA : 0);
// 		cycle->waiting_die += cycle->cycles_to_die;
// 		ft_printf("WAITING DIE = %d\n", cycle->waiting_die);

// 		cycle->lives_in_current_period_all = 0;
// 		ft_bzero(cycle->lives_in_current_period, sizeof(int) * MAX_PLAYERS);
// 	}
// 	if (cycle->cycles_to_die <= 0)
// 		return (1);
// 	return (0);
// }


int		vm_check_cursor(uint8_t map[MEM_SIZE][4],
						t_cursor **cur, t_cycle *cycle)
{
	t_cursor	*copy;
	t_cursor	*for_del;

	if (cycle->cycles_to_die <= 0)
		return (1);
	if (cycle->cycle_num == cycle->waiting_die /* + 1 */)
	{
		copy = *cur;

//		if (*cur == NULL) // ЭТИ СТОКИ ДОЛЖНЫ БЫТЬ ЛИШНИМИ
//			return (1); //
		while (copy)
		{
			if (copy->next && copy->next->live + cycle->cycles_to_die <= cycle->cycle_num)
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
			////////////////////////////////      printf
			if (cycle->log)
				ft_printf("Cycle to die is now %d\n", cycle->cycles_to_die);
			///////////////////////////////
			cycle->checks = 0;
		}
//		else
//			cycle->checks++;
		cycle->waiting_die += cycle->cycles_to_die;
		cycle->lives_in_current_period_all = 0;
		ft_bzero(cycle->lives_in_current_period, sizeof(int) * MAX_PLAYERS);
	}
	return (0);
}
