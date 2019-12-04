/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:17:03 by bford             #+#    #+#             */
/*   Updated: 2019/12/04 20:29:14 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

int			main(int argc, char **argv)
{
	t_player	*player;
	int			cycle;

	cycle = 0;
	//printf("RES = %d\n", ft_valid_input(argc, argv));
	player = ft_init_input(argc, argv, ft_valid_input(argc, argv));
	if (!player)
		printf("POSOSI\n");
	return (ft_lstdel_player(player));
}
