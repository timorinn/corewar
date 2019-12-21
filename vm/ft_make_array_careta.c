/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array_careta.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:13:13 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 14:20:37 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//extern int g_operation[16];

t_cursor	*ft_make_array_careta(t_player *player, unsigned char map[MEM_SIZE][4])
{
	t_cursor	*array;
	int		len;
	int		i;
	int		reg;

	len = ft_lstlen_player(player);
	if (!(array = (t_cursor *)malloc(sizeof(t_cursor) * (len + 1))))
		return (NULL);
	i = len - 1;
	while (player)
	{
		array[i].num = i;
		array[i].carry = 0;
		array[i].size = len;
		array[i].cooldown = 0;
		array[i].play_num = player->num;
		array[i].position = MEM_SIZE / len * (len - i - 1);
		array[i].operation = map[array[i].position][0];
		array[i].cooldown = g_operation[array[i].operation - 1];
		array[i].registr[0] = -player->num;
		reg = 1;
		while (reg < REG_NUMBER && ++reg)
			array[i].registr[reg - 1] = 0;
		i--;
		player = player->next;
	}
	return (array);
}
