/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 00:43:38 by bford             #+#    #+#             */
/*   Updated: 2019/12/29 21:36:45 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_delete_one_cursor(t_cursor **cur, int i, int size)
{
	t_cursor	*new;

	if (!(new = malloc(sizeof(t_cursor) * size)))
		return (0);
	ft_memmove(new, *cur, i * sizeof(t_cursor));
	ft_memmove(new + i, *cur + i + 1, (size - i) * sizeof(t_cursor));
	free (*cur);
	*cur = new;
	return (1);
}

int		vm_check_cursor(uint8_t map[MEM_SIZE][4],
						t_cursor **cur, t_cycle *cycle)
{
	map+=0;

	int		i;

	if ((cycle->cycle_num % CYCLE_TO_DIE == 0 &&
	cycle->cycle_num > 0) || cycle->cycles_to_die <= 0)
	{
		i = 0;
		while (i < cycle->cur_len)
		{
			if ((*cur)[i].live + CYCLE_TO_DIE < cycle->cycle_num)
			{
				if (!vm_delete_one_cursor(cur, i, --cycle->cur_len))
					return (0);
			}
			i++;
		}
		cycle->last_period_live = 0;
	}
	return (1);
}
