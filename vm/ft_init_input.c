/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:48:03 by bford             #+#    #+#             */
/*   Updated: 2019/12/06 19:17:58 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_init_numbers(int *nums)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS && ++i)
		nums[i - 1] = 0;
}

int			ft_make_player_num(t_player *player, int *numbers)
{
	int		i;
	int		len;

	i = 0;
	len = ft_lstlen_player(player);
	while (player)
	{
		if (player->num == 0)
		{
			while (numbers[i])
				i++;
			player->num = ++i;
		}
		if (player->num > len)
			return (0);
		player = player->next;
	}
	return (1);
}

t_player	*ft_init_input(int argc, char **argv, int valid, int dump)
{
	t_player	*player;
	int			numbers[MAX_PLAYERS];
	int			i;

	i = 1;
	player = NULL;
	if (!valid)
		return (NULL);
	i += (dump != -1 ? 2 : 0);
	ft_init_numbers(numbers);
	argc -= (ft_strcmp(argv[argc - 1], "-v") ? 0 : 1);
	while (i < argc && ++i)
		if (!ft_init_player(argv, &i, &player, numbers))
			return (NULL + ft_lstdel_player(player));
	return (ft_make_player_num(player, numbers) ?
	player : NULL + ft_lstdel_player(player) + ft_error(4, 0));
}
