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

inline bool	op_all_fork(uint8_t map[MEM_SIZE][4], t_cycle *cycle,
					t_cursor **cur, int32_t (*operation)(int32_t, int32_t))
{
	t_ind		ind;
	t_cursor	*newcur;
	t_cursor	*nowcur;
	int			size;

	nowcur = cycle->now_cur;
	size = cycle->cur_len++;
	if (!(newcur = malloc(sizeof(t_cursor) * (size + 1))))
	 	return (FALSE);
	ft_init_t_ind(map, nowcur->position + 1, &ind);
	ft_memmove(newcur + 1, *cur, size * sizeof(t_cursor));
	
	while (size--)
		newcur[size].size = cycle->cur_len;

	ft_memcpy(newcur, nowcur, sizeof(t_cursor));
	//newcur[0].num = nowcur->size;
	newcur[0].num = cycle->new_cur_num++;
	newcur[0].position = operation(nowcur->position, ind.data);
	newcur[0].operation = map[newcur[0].position][0];
	if (newcur[0].operation > 0 && newcur[0].operation < REG_NUMBER + 1)
		newcur[0].cooldown = g_operation[newcur[0].operation - 1] - 1;
	else
		newcur[0].cooldown = 0;
	

	// size = nowcur[0].size - 1;
	// if (!(newcur = (t_cursor *)malloc(sizeof(t_cursor) * (size + 2))))
	// 	return (FALSE);
	// ft_init_t_ind(map, nowcur->position + 1, &ind);

	// while (size >= 0)
	// {
	// 	newcur[size + 1] = (*cur)[size];
	// 	if (newcur[size + 1].num == nowcur->num)
	// 		newcur[size + 1].position = (nowcur->num + 3) % MEM_SIZE;
	// 	newcur[size + 1].size = nowcur[0].size + 1;
	// 	size--;
	// }
	// newcur[0] = *nowcur;
	// newcur[0].size = nowcur->size + 1;
	// newcur[0].num = nowcur->size;
	// /*
	// newcar[0].position = (cur->position + ind.data % IDX_MOD > 0 ?
	// (cur->position + ind.data % IDX_MOD) % MEM_SIZE :
	// 4096 + (cur->position + ind.data % IDX_MOD));
	// */
	// newcur[0].position = operation(nowcur->position, ind.data);
	// newcur[0].operation = map[newcur[0].position][0];
	// newcur[0].cooldown = newcur[0].operation > 0 &&
	// 		newcur[0].operation < REG_NUMBER + 1 ?
	// 		g_operation[newcur[0].operation /**/ - 1] /* */ - 1 : /* 1 */ 0;

	free(*cur);
	*cur = newcur;
	return (TRUE);
}
