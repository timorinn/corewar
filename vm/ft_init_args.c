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

void	ft_init_args(unsigned char map[4096][4],
int position, unsigned int args[4])
{
	int		arg_type;

	arg_type = position == 4095 ? map[0][0] : map[position + 1][0];
	args[0] = (arg_type >> 6) & 3;
	args[1] = (arg_type >> 4) & 3;
	args[2] = (arg_type >> 2) & 3;
	args[3] = arg_type & 3;
}
