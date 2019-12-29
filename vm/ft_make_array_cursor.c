/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array_cursor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:13:13 by bford             #+#    #+#             */
/*   Updated: 2019/12/29 17:01:55 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_cursor	*ft_make_array_cursor(t_player *player, uint8_t map[MEM_SIZE][4])
{
	t_cursor	*cur;
	int			len;
	int			i;
	//int			reg;

	len = ft_lstlen_player(player);
	if (!(cur = (t_cursor *)malloc(sizeof(t_cursor) * len)))
		return (NULL);
	i = len - 1;
	while (player)
	{
		cur[i].num = len - i - 1;
		cur[i].carry = 0;
		cur[i].live = 0;
		//cur[i].size = len;
		cur[i].cooldown = 0;
		cur[i].play_num = player->num;
		cur[i].position = MEM_SIZE / len * (len - i - 1);
		cur[i].operation = map[cur[i].position][0];
		cur[i].cooldown = g_operation[cur[i].operation - 1];
		ft_bzero(cur[i].registr, (REG_NUMBER + 1) * sizeof(int));
		//reg = 0;
		//while (reg < REG_NUMBER && ++reg)
		//	cur[i].registr[reg - 1] = 0;
		cur[i].registr[1] = -player->num;
		i--;
		player = player->next;
	}
	return (cur);
}
