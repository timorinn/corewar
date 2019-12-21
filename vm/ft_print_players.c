/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:45:54 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 18:55:12 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int     ft_print_players(t_player *player)
{
    ft_putstr("Introducing contestants...\n");
    while (player)
    {
        ft_putstr("* Player ");
        ft_putnbr(player->num);
        ft_putstr(", weighing ");
        ft_putnbr(player->size);
        ft_putstr(" bytes, \"");
        ft_putstr(player->name);
        ft_putstr("\" (\"");
        ft_putstr(player->comment);
        ft_putstr("\") !\n");
        player = player->next;
    }
    return (1);
}
