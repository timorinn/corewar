/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:01:00 by bford             #+#    #+#             */
/*   Updated: 2019/12/19 14:11:03 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_init_args(uint8_t map[MEM_SIZE][4],
int position, uint8_t args[4])
{
	int		arg_type;

	arg_type = (position == (MEM_SIZE - 1) ? map[0][0] : map[position + 1][0]);
	args[0] = (arg_type >> 6) & 3;
	args[1] = (arg_type >> 4) & 3;
	args[2] = (arg_type >> 2) & 3;
	args[3] = arg_type & 3;
}
