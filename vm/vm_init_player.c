/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:59:08 by bford             #+#    #+#             */
/*   Updated: 2019/12/14 16:41:47 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_init_player.h"

inline static int8_t	check_magic(char *start)
{
	return (*(uint32_t *)start = COREWAR_EXEC_MAGIC);
}

inline static int8_t	init_new_player(int fd, t_player *player)
{
	char	buf[COMMENT_LENGTH + 1];

	return (((!(buf[4] = '\0') && (read(fd, buf, 4) != 4 ||
	!check_magic(buf)) && !vm_error(2, 0)) ||
	((!(buf[PROG_NAME_LENGTH] = '\0')
	&& read(fd, buf, PROG_NAME_LENGTH) != PROG_NAME_LENGTH &&
	!vm_error(2, 0)) || !make_player_name(player, buf)) ||
	((!(buf[4] -= buf[4]) && (read(fd, buf, 4) != 4 ||
	*(uint32_t *)buf != 0) && !vm_error(2, 0))) ||
	((!(buf[4] -= buf[4]) && read(fd, buf, 4) != 4 && !vm_error(2, 0)) ||
	!make_code_size(&(player->size), buf)) ||
	((!(buf[COMMENT_LENGTH] = '\0') &&
	read(fd, buf, COMMENT_LENGTH) != COMMENT_LENGTH && !vm_error(2, 0)) ||
	!make_player_comment(player, buf)) ||
	((!(buf[4] -= buf[4]) && (read(fd, buf, 4) != 4 ||
	*(uint32_t *)buf != 0) && !vm_error(2, 0))) ||
	((!(buf[player->size] -= buf[player->size]) &&
	read(fd, buf, player->size + 1) != player->size && !vm_error(2, 0)) ||
	!make_player_code(player, buf, player->size))) ? 0 : 1);
}

inline static int8_t	make_lst_player(int fd, t_player **player, int num)
{
	t_player	*copy;

	if (!(*player))
	{
		if (!(*player = vm_lstnew_player(num)))
			return (0);
		copy = *player;
	}
	else
	{
		copy = *player;
		while (copy->next)
			copy = copy->next;
		if (!(copy->next = vm_lstnew_player(num)))
			return (0);
		copy = copy->next;
	}
	return (init_new_player(fd, copy));
}

int8_t					vm_init_player(char **argv, int *i, t_player **player,
		int8_t *numbers)
{
	int	num;
	int	fd;

	num = (!ft_strcmp(argv[*i - 1], "-n") && (*i += 2) ?
	ft_atoi(argv[*i - 2]) : 0);
	num ? numbers[num - 1] = 1 : 0;
	fd = open(argv[*i - 1], O_RDONLY);
	if (fd == -1 || (read(fd, NULL, 0) == -1 && close(fd)))
		return (vm_error(1, argv[*i - 1]));
	return (make_lst_player(fd, player, num) + close(fd) ? 1 : 0);
}
