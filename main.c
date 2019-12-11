/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:17:03 by bford             #+#    #+#             */
/*   Updated: 2019/12/11 13:57:59 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

int			ft_visu(int argc, char **argv)
{
	return (!ft_strcmp(argv[argc - 1], "-v"));
}

void		ft_print_code(t_player *player)
{
	int				i;
	int				size;
	unsigned char	*code;

	i = 0;
	size = player->size;
	code = player->code;
	while (i < size && ++i)
	{
		ft_print_hex(code[i - 1]);
		write(1, " ", 1);
	}
	write(1, "\n\n", 2);
}

void		ft_print_player_param(t_player *player, int code)
{
	while (player)
	{
		printf("Player[%d] | Name = %s\n", player->num, player->name);
		printf("	%s\n", player->comment);
		if (code)
			ft_print_code(player);
		player = player->next;
	}
}

int			ft_init_dump(int argc, char **argv)
{
	return (argc > 1 && !ft_strcmp(argv[1], "-dump") ? ft_atoi(argv[2]) : -1);
}

int			main(int argc, char **argv)
{
	t_player	*player;
	int			dump;

	dump = ft_init_dump(argc, argv);
	player = ft_init_input(argc, argv, ft_valid_input(argc, argv), dump);
	ft_map(dump, player, ft_visu(argc, argv));

	ft_print_player_param(player, 0);

	return (ft_lstdel_player(player));
}
