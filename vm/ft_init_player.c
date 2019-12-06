/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:59:08 by bford             #+#    #+#             */
/*   Updated: 2019/12/06 16:37:07 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_print_bit(uint32_t n)
{
	uint8_t	shift;

	shift = 0;
	while (shift < 32)
	{
		if ((shift & 0b111) == 0)
			printf(" ");
		printf("%d", (n & ((uint32_t)1 << shift)) ? 1 : 0);
		shift++;
	}
	printf("_\n");
}

int			ft_make_player_name(t_player *player, char *name)
{
	return ((player->name = ft_strdup(name)) ? 1 : ft_error(12, 0));
}

int			ft_make_player_comment(t_player *player, char *comment)
{
	return ((player->comment = ft_strdup(comment)) ? 1 : ft_error(12, 0));
}

int			ft_make_player_code(t_player *player, char *code, int code_size)
{
	return ((player->code = ft_strndupu(code, code_size)) ? 1 : ft_error(12, 0));
}

typedef union	u_bits
{
	uint8_t bits[4];
	uint32_t data;
}				t_bits;

int			ft_make_code_size(int *code_size, char *buf)
{
	t_bits b1;
	t_bits b2;

	b1.data = *(uint32_t *)buf;
	b2.bits[0] = b1.bits[3];
	b2.bits[1] = b1.bits[2];
	b2.bits[2] = b1.bits[1];
	b2.bits[3] = b1.bits[0];
	*code_size = b2.data;
	return (*code_size >= 0 && *code_size <= CHAMP_MAX_SIZE ?
	1 : ft_error(9, 0));
}

int			ft_check_start_file(char *start)
{
	return (*(uint32_t *)start == 4085508608);
}

int			ft_init_new_player(int fd, t_player *player)
{
	char	buf[COMMENT_LENGTH + 1];

	return (((!(buf[4] = '\0') && (read(fd, buf, 4) != 4 ||
	!ft_check_start_file(buf)) && !ft_error(2, 0)) ||
	((!(buf[PROG_NAME_LENGTH] = '\0')
	&& read(fd, buf, PROG_NAME_LENGTH) != PROG_NAME_LENGTH &&
	!ft_error(2, 0)) || !ft_make_player_name(player, buf)) ||
	((!(buf[4] -= buf[4]) && (read(fd, buf, 4) != 4 ||
	*(uint32_t *)buf != 0) && !ft_error(2, 0))) ||
	((!(buf[4] -= buf[4]) && read(fd, buf, 4) != 4 && !ft_error(2, 0)) ||
	!ft_make_code_size(&(player->size), buf)) ||
	((!(buf[COMMENT_LENGTH] = '\0') &&
	read(fd, buf, COMMENT_LENGTH) != COMMENT_LENGTH && !ft_error(2, 0)) ||
	!ft_make_player_comment(player, buf)) ||
	((!(buf[4] -= buf[4]) && (read(fd, buf, 4) != 4 ||
	*(uint32_t *)buf != 0) && !ft_error(2, 0))) ||
	((!(buf[player->size] -= buf[player->size]) &&
	read(fd, buf, player->size) != player->size && !ft_error(2, 0)) ||
	!ft_make_player_code(player, buf, player->size))) ? 0 : 1);
}

int			ft_make_lst_player(int fd, t_player **player, int num)
{
	t_player	*copy;

	copy = NULL;
	if (!(*player))
	{
		if (!(*player = ft_lstnew_player(num)))
			return (0);
		copy = *player;
	}
	else
	{
		copy = *player;
		while (copy->next)
			copy = copy->next;
		if (!(copy->next = ft_lstnew_player(num)))
			return (0);
		copy = copy->next;
	}
	return (ft_init_new_player(fd, copy));
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

	if (fd == -1 || (read(fd, check, 0) == -1 && close(fd)))
		return (ft_error(1, argv[*i - 1]));
	return (ft_make_lst_player(fd, player, num) + close(fd) ? 1 : 0);
}
