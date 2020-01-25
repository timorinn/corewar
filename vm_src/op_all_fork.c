/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_all_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:10:30 by bford             #+#    #+#             */
/*   Updated: 2020/01/25 14:10:31 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_copy_cursor(t_cursor *head, t_cursor *for_copy)
{
	head->carry = for_copy->carry;
	head->play_num = for_copy->play_num;
	head->live = for_copy->live;
	ft_memmove(head->registr, for_copy->registr,
			sizeof(int) * (REG_NUMBER + 1));
}

inline bool	op_all_fork(uint8_t map[MEM_SIZE][4], t_cycle *cycle,
					t_cursor **cur, int32_t (*operation)(int32_t, int32_t))
{
	t_cursor	*head_cur;
	t_cursor	*now_cur;
	t_ind		ind;

	now_cur = cycle->now_cur;
	if (!(head_cur = malloc(sizeof(t_cursor))))
		exit(1);
	cycle->cur_len++;
	vm_init_t_ind(map, now_cur->position + 1, &ind);
	head_cur->position = operation(now_cur->position, ind.data);
	if (cycle->log == true)
		ft_printf(" %d (%d)\n", ind.data, head_cur->position);
	head_cur->num = ++cycle->processes_qty;
	map[head_cur->position][2] += 1;
	map[now_cur->position][2] -= 1;
	now_cur->position = (now_cur->position + 3) % MEM_SIZE;
	map[now_cur->position][2] += 1;
	now_cur->operation = -1;
	now_cur->cooldown = 0;
	head_cur->operation = -1;
	head_cur->cooldown = 0;
	vm_copy_cursor(head_cur, now_cur);
	head_cur->next = *cur;
	*cur = head_cur;
	return (true);
}
