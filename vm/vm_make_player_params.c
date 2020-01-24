/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_make_player_params.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:22:19 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:22:36 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline int8_t	make_player_name(t_player *player, char *name)
{
	return ((player->name = ft_strdup(name)) ? 1 : vm_error(12, 0));
}

inline int8_t	make_player_comment(t_player *player, char *comment)
{
	return ((player->comment = ft_strdup(comment)) ? 1 : vm_error(12, 0));
}

inline int8_t	make_player_code(t_player *player, char *code, int code_size)
{
	return ((player->code = ft_strndupu(code, code_size)) ?
			1 : vm_error(12, 0));
}

inline int8_t	make_code_size(int *code_size, char *buf)
{
	t_dir bit;

	bit.bytes[3] = buf[0];
	bit.bytes[2] = buf[1];
	bit.bytes[1] = buf[2];
	bit.bytes[0] = buf[3];
	*code_size = bit.data;
	return (*code_size >= 0 && *code_size <= CHAMP_MAX_SIZE ?
			1 : vm_error(9, 0));
}
