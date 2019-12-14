/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:59:37 by bford             #+#    #+#             */
/*   Updated: 2019/12/14 19:59:54 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_init_t_ind(unsigned char map[4096][4],
int position, t_ind *ind)
{
	(*ind).bits[0] = (position + 1 > 4095 ?
	map[position + 1 - 4096][0] : map[position + 1][0]);
	(*ind).bits[1] = (position > 4095 ?
	map[position - 4096][0] : map[position][0]);
}
