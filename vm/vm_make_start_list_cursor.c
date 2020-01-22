/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_make_start_list_cursor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:13:13 by bford             #+#    #+#             */
/*   Updated: 2020/01/22 19:44:05 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static void		init_cursor(t_cursor *cursor, t_player *player,
							uint8_t map[MEM_SIZE][4], int16_t position)
{
	cursor->play_num = player->num;
	cursor->carry = 0;
	cursor->position = position;
	cursor->operation = map[cursor->position][0];
	cursor->cooldown = g_operation[cursor->operation - 1];
	ft_bzero(cursor->registr, sizeof(int) * (REG_NUMBER + 1));
	cursor->registr[1] = -player->num;
	cursor->next = NULL;
}

inline static t_cursor	*create_cursor(uint8_t map[MEM_SIZE][4],
		t_player *player, int16_t position, t_cursor *start)
{
	t_cursor	*cursor;

	if (!(cursor = malloc(sizeof(t_cursor))))
		exit(vm_error(12, 0));
	init_cursor(cursor, player, map, position);
	if (start != NULL)
	{
		cursor->next = start;
		cursor->num = start->num + 1;
	}
	else
		cursor->num = 1;
	return (cursor);
}

t_cursor				*vm_make_start_list_cursor(t_player *player,
										uint8_t map[MEM_SIZE][4])
{
	t_cursor	*cursor;
	t_cursor	*start;
	int16_t		position;
	int16_t		pos_offset;

	pos_offset = MEM_SIZE / vm_lstlen_player(player);
	position = 0;
	if (!(cursor = malloc(sizeof(t_cursor))))
		exit(vm_error(12, 0));
	cursor->num = 1;
	init_cursor(cursor, player, map, position);
	start = cursor;
	player = player->next;
	while (player)
	{
		position += pos_offset;
		start = create_cursor(map, player, position, start);
		player = player->next;
	}
	return (start);
}
