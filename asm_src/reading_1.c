/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:48:50 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 20:57:23 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_delim(char c)
{
	if (
		c == ' ' ||
		c == '\t' ||
		c == '\n' ||
		c == SEPARATOR_CHAR ||
		c == DIRECT_CHAR ||
		c == '\0' ||
		c == LABEL_CHAR)
		return (1);
	return (0);
}

int			is_delop(char c)
{
	if (
		c == ' ' ||
		c == '\t' ||
		c == '\n' ||
		c == SEPARATOR_CHAR ||
		c == DIRECT_CHAR ||
		c == '\0' ||
		c == LABEL_CHAR ||
		c == '-')
		return (1);
	return (0);
}

int			is_char_labl(char c, char *pattern)
{
	int i;

	i = 0;
	while (pattern[i])
	{
		if (pattern[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_point		get_point(t_all *gen)
{
	t_point	point;

	point.x = gen->point.x;
	point.y = gen->point.y;
	return (point);
}

int			increment_point(t_all *gen)
{
	if (gen->file[gen->i] == '\n')
	{
		gen->point.x++;
		gen->point.y = 0;
	}
	gen->i++;
	gen->point.y++;
	return (0);
}
