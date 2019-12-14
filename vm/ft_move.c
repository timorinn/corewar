/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 22:27:01 by bford             #+#    #+#             */
/*   Updated: 2019/12/14 22:27:15 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_move(unsigned int args[4], char *valid, int dir)
{
	int		i;
	int		move;

	i = 0;
	move = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (valid[i] - '0')
		{
			if (args[i] == 1)
				move += 1;
			else if (args[i] == 2)
				move += dir;
			else if (args[i] == 3)
				move += 2;
		}
		i++;
	}
	return (move);
}