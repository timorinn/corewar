/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:59:37 by bford             #+#    #+#             */
/*   Updated: 2019/12/19 14:06:50 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_init_t_ind(unsigned char map[MEM_SIZE][4],
int position, t_ind *ind)
{
	//(*ind).bytes[0] = (position + 1 > (MEM_SIZE - 1) ?
	//map[position + 1 - MEM_SIZE][0] : map[position + 1][0]);
	(*ind).bytes[0] = map[(position + 1) % MEM_SIZE][0];
	//(*ind).bytes[1] = (position > (MEM_SIZE - 1) ?
	//map[position - MEM_SIZE][0] : map[position][0]);
	(*ind).bytes[1] = map[position % MEM_SIZE][0];
}
