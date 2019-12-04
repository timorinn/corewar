/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:51:53 by bford             #+#    #+#             */
/*   Updated: 2019/12/04 20:45:33 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player		*ft_lstnew_player(int num, t_player *next)
{
	t_player	*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->num = num;
	player->name = NULL;
	player->comment = NULL;
	player->code = NULL;
	player->next = next;
	return (player);
}
