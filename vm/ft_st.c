/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:44:28 by bford             #+#    #+#             */
/*   Updated: 2019/12/13 13:30:38 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int     ft_st(unsigned char map[4096][4], careta *car)
{
	int				arg_type;
	unsigned char	args[4];

    arg_type = (car[0].position == 4095 ? map[0][0] : map[car[0].position + 1][0]);

	args[0] = (arg_type >> 6) & 3;
	args[1] = (arg_type >> 4) & 3;
	args[2] = (arg_type >> 2) & 3;
	args[3] = arg_type & 3;

	printf("t_reg [0] = %d %x\n", args[0], args[0]);

	//printf("arg_type = %x | args %d %d %d %d\n", map[arg_type][0], args[0], args[1], args[2], args[3]);


	return (1);
}
