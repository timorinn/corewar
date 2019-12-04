/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:59:08 by bford             #+#    #+#             */
/*   Updated: 2019/12/04 20:45:09 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_print_bin(char c)
{
	char 	t[] = "0123456789abcdef";
	ft_putchar(t[c / 16 % 16]);
	ft_putchar(t[c % 16]);
}

int			ft_player_params(t_player *player, char *buf, int i)
{
	if (i > 4 && i < 4 + PROG_NAME_LENGTH)
	{
		if (!player->name)
			return ((player->name = ft_strdup(buf)) ? 1 : 0);
		return ((player->name = ft_strjoin_free(player->name, buf)) ? 1 : 0);
	}
	return (1);
}

t_player	*ft_init_new_player(int fd, int num, t_player *next)
{
	t_player	*player;
	char		buf[2];
	int			i;

	if (!(player = ft_lstnew_player(num, next)))
		return (NULL);
	i = 0;
	while (read(fd, buf, 1) == 1 && ++i && !(buf[1] = '\0'))
	{
		//ft_print_bin(*buf);
		//i % 2 ? 0 : write(1, " ", 1);
		if (!ft_player_params(player, buf, i))
			return (NULL);
	}
	if (player->name)
		printf("Player_name = %s\n", player->name);
	//write(1, "\n", 1);
	return (player);
}

int			ft_make_lst_player(int fd, t_player **player, int num)
{
	t_player	*next;

	if (!(*player))
		return ((*player = ft_init_new_player(fd, num, NULL)) ? 1 : 0);
	next = *player;
	return ((*player = ft_init_new_player(fd, num, next)) ? 1 : 0);
}

int			ft_init_player(char **argv, int *i, t_player **player, int *numbers)
{
	int		num;
	int		fd;
	char	check[1];

	num = (!ft_strcmp(argv[*i - 1], "-n") && (*i += 2) ?
	ft_atoi(argv[*i - 2]) : 0);
	num ? numbers[num - 1] = 1 : 0;
	fd = open(argv[*i - 1], O_RDONLY);

	printf("Num = %d | File = %s\n", num, argv[*i - 1]);

	if ((fd == -1 || (read(fd, check, 0) == -1 && close(fd))) &&
	!ft_putstr_fd("Error: invalid file: ", 2) &&
	!ft_putendl_fd(argv[*i - 1], 2))
		return (0);
	return (ft_make_lst_player(fd, player, num) + close(fd) ? 1 : 0);
}
