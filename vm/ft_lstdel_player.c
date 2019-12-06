/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:56:04 by bford             #+#    #+#             */
/*   Updated: 2019/12/06 13:10:05 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_lstdel_player(t_player *player)
{
	t_player	*buf;

	while (player)
	{
		buf = player->next;
		if (player->name)
		{
			free(player->name);
			player->name = NULL;
		}
		if (player->comment)
		{
			free(player->comment);
			player->comment = NULL;
		}
		if (player->code)
		{
			free(player->code);
			player->code = NULL;
		}
		free(player);
		player = NULL;
		player = buf;
	}
	return (0);
}
