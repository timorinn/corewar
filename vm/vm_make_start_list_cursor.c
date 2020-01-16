/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_make_start_list_cursor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:13:13 by bford             #+#    #+#             */
/*   Updated: 2020/01/05 18:01:13 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		vm_init_cursor(t_cursor *cursor, t_player *player,
							uint8_t map[MEM_SIZE][4], int position)
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

t_cursor	*vm_make_start_list_cursor(t_player *player, int8_t player_qty,
										uint8_t map[MEM_SIZE][4])
{
	t_cursor	*cursor;
	t_cursor	*start;
	int			position;
	int32_t 	cursor_num;

	position = MEM_SIZE / ft_lstlen_player(player);
	if (!(cursor = malloc(sizeof(t_cursor))))
		exit(1);
	cursor_num = 1;
	cursor->num = cursor_num++;
	vm_init_cursor(cursor, player, map, 0);
	start = cursor;
	player = player->next;
	while (player)
	{
		if (!(cursor->next = malloc(sizeof(t_cursor))))
			exit(1);
		cursor = cursor->next;
		cursor->num = cursor_num++;
		vm_init_cursor(cursor, player, map, position);
		position += position;
		player = player->next;
	}
	return (start);
}
