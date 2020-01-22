/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:45:54 by bford             #+#    #+#             */
/*   Updated: 2020/01/22 17:18:50 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int     vm_print_players(t_player *player)
{
    ft_putstr("Introducing contestants...\n");
    while (player)
    {
        ft_printf("* Player %d, weighting %d bytes, \"%s\" (\"%s\") !\n",
                player->num, player->size, player->name, player->comment);
        player = player->next;
    }
    return (1);
}
