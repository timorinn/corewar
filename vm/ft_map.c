/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:48:15 by bford             #+#    #+#             */
/*   Updated: 2019/12/06 19:14:46 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_add_player(unsigned char *map, t_player *player, int start)
{
	int				size;
	unsigned char	*code;
	int				i;

	i = 0;
	code = player->code;
	size = player->size;
	while (i < size && ++i)
		map[start + i - 1] = code[i - 1];
	return (1);
}

t_player	*ft_find_player(int num, t_player *player)
{
	while (player->num != num)
		player = player->next;
	return (player);
}

int		ft_init_map(unsigned char *map, t_player *player)
{
	int		i;
	int		len;

	len = ft_lstlen_player(player);
	i = 0;
	while (i < MEM_SIZE + 1 && ++i)
		map[i - 1] = 0;
	i = 0;
	while (i < len && ++i)
		ft_add_player(map, ft_find_player(i, player), MEM_SIZE / len * (i - 1));
	return (1);
}


int		ft_print_map(unsigned char *map)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE && ++i)
	{
		ft_print_hex(map[i - 1]);
		write(1, i % 64 ? " " : "\n", 1);
	}
	return (1);
}

int		ft_map(int dump, t_player *player, int v)
{
	unsigned char	map[MEM_SIZE + 1];

	dump+=0;v+=0;

	if (!player)
		return (0);
	ft_init_map(map, player);
	if (v)
		ft_print_map(map);
	return (1);
}
