/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_all_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:12:30 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 19:32:44 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// inline bool	op_all_fork(uint8_t map[MEM_SIZE][4], t_cycle *cycle,
// 					t_cursor **cur, int32_t (*operation)(int32_t, int32_t))
// {
// 	t_ind		ind;
// 	t_cursor	*newcur;
// 	t_cursor	*nowcur;
// 	int			size;

// 	nowcur = cycle->now_cur;
// 	size = ++cycle->cur_len;
// 	if (!(newcur = malloc(sizeof(t_cursor) * size)))
// 	 	return (FALSE);
// 	vm_init_t_ind(map, nowcur->position + 1, &ind);
// 	ft_memmove(newcur + 1, *cur, (size - 1) * sizeof(t_cursor));
// 	ft_memcpy(newcur, nowcur, sizeof(t_cursor));
// 	while (--size)
// 		if (newcur[size].num == nowcur->num)
// 		{
// 			map[nowcur->position][2] = 0; // new
// 			newcur[size].position = (nowcur->position + 3) % MEM_SIZE ;
// 			map[newcur[size].position][2] = 1; // new
// 		}
// 	//ft_memcpy(newcur, nowcur, sizeof(t_cursor));
// 	newcur[0].num = cycle->new_cur_num++;
// 	newcur[0].position = operation(nowcur->position, ind.data);

// 	map[newcur[0].position][2] = 1; // new

// 	newcur[0].operation = map[newcur[0].position][0];
// 	if (newcur[0].operation > 0 && newcur[0].operation < REG_NUMBER + 1)
// 		newcur[0].cooldown = g_operation[newcur[0].operation - 1] - 1;
// 	else
// 		newcur[0].cooldown = 0;
	
// 	free(*cur);
// 	*cur = newcur;
// 	return (TRUE);
// }

void		vm_copy_cursor(t_cursor *head, t_cursor *for_copy)
{
	head->carry = for_copy->carry;
	head->play_num = for_copy->play_num;
	head->live = for_copy->live;
	ft_memmove(head->registr, for_copy->registr, sizeof(int) * (REG_NUMBER + 1));
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

///	head_cur->operation = map[head_cur->position][0];
///	if (head_cur->operation > 0 && head_cur->operation < 17)
///		head_cur->cooldown = g_operation[head_cur->operation - 1] - 1;
///	else
///		head_cur->cooldown = 0;

	head_cur->operation = -1;
	head_cur->cooldown = 0;

	vm_copy_cursor(head_cur, now_cur);
	head_cur->next = *cur;
	*cur = head_cur;
//
	// if (cycle->log == true)
	// 	ft_putendl(" It could be fork/lfork args here, but there is this text.");
//
	return (true);
}