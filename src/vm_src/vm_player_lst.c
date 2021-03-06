/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_player_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:03:03 by kpsylock          #+#    #+#             */
/*   Updated: 2020/01/24 12:58:23 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int8_t		vm_lstlen_player(t_player *player)
{
	int	i;

	i = 0;
	while (player)
	{
		player = player->next;
		i++;
	}
	return (i);
}

t_player	*vm_lstnew_player(int num)
{
	t_player	*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL + vm_error(12, 0));
	player->num = num;
	player->name = NULL;
	player->comment = NULL;
	player->code = NULL;
	player->size = 0;
	player->next = NULL;
	return (player);
}

int			vm_lstdel_player(t_player *player)
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
