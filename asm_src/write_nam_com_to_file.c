/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nam_com_to_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:22:43 by swedde            #+#    #+#             */
/*   Updated: 2020/01/25 16:49:30 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	write_string_to_file(int fd, char *s, int len)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (s[i])
	{
		c = s[i];
		write(fd, &c, 1);
		i++;
	}
	c = 0;
	while (i < len)
	{
		write(fd, &c, 1);
		i++;
	}
	return (0);
}

int			write_nam_com_to_file(t_all *gen, int len, int type)
{
	t_token *token;

	token = gen->token;
	while (token->type != type)
		token = token->next;
	write_string_to_file(gen->fd, token->content, len);
	write_int_to_file(gen, 0);
	return (1);
}
