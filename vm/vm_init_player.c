/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:59:08 by bford             #+#    #+#             */
/*   Updated: 2020/01/22 16:34:05 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_init_player.h"

inline static int8_t	check_magic(const char *start)
{
	uint32_t		magic;
	magic_header 	true_magic;

	true_magic.bytes[0] = (COREWAR_EXEC_MAGIC >> 24) & 0xFF;
	true_magic.bytes[1] = (COREWAR_EXEC_MAGIC >> 16) & 0xFF;
	true_magic.bytes[2] = (COREWAR_EXEC_MAGIC >> 8) & 0xFF;
	true_magic.bytes[3] = (COREWAR_EXEC_MAGIC >> 0) & 0xFF;
	magic = *(uint32_t *)start;
	if (magic == true_magic.all)
		return (true);
	else
		return (false);
}

inline static void	init_new_player(int fd, t_player *player)
{
	char	buf[COMMENT_LENGTH + 1];

	ft_bzero(buf, sizeof(char) * (COMMENT_LENGTH + 1));
	if (((!(buf[4] = '\0') && (read(fd, buf, 4) != 4 ||
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
	!make_player_code(player, buf, player->size))))
		exit(1);
}

inline static void	make_lst_player(int fd, t_player **player, int num)
{
	t_player	*copy;

	if (!(*player))
	{
		if (!(*player = vm_lstnew_player(num)))
			exit(vm_error(12, 0));
		copy = *player;
	}
	else
	{
		copy = *player;
		while (copy->next)
			copy = copy->next;
		if (!(copy->next = vm_lstnew_player(num)))
			exit(vm_error(12, 0));
		copy = copy->next;
	}
	init_new_player(fd, copy);
}

void				vm_init_player(char **argv, int *i, t_player **player,
		int8_t *numbers)
{
	int	num;
	int	fd;

	num = (!ft_strcmp(argv[*i - 1], "-n") && (*i += 2) ?
	ft_atoi(argv[*i - 2]) : 0);
	num ? numbers[num - 1] = 1 : 0;
	fd = open(argv[*i - 1], O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) == -1)
		exit(vm_error(1, argv[*i - 1]));
	make_lst_player(fd, player, num);
	close(fd);
}
