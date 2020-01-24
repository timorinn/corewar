/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_player.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:24:53 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:25:00 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_INIT_PLAYER_H
# define VM_INIT_PLAYER_H

# include "vm.h"

int8_t	make_player_name(t_player *player, char *name);
int8_t	make_player_comment(t_player *player, char *comment);
int8_t	make_player_code(t_player *player, char *code, int code_size);
int8_t	make_code_size(int *code_size, char *buf);

#endif
