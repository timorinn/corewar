/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_single.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:59:50 by bford             #+#    #+#             */
/*   Updated: 2019/12/21 19:17:31 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_print_map_single(unsigned char map[MEM_SIZE][4])
{
	int		i;

	i = 1;
	while (i < MEM_SIZE + 1)
	{
		if (i % 64 == 1)
			printf("0x%03x0 : ", i / 16);
		printf("%02x ", map[i - 1][0]);
		if (i % 64 == 0)
			printf("\n");
		i++;
	}
	return (1);
}