/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_t_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:59:37 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:24:24 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_init_t_ind(uint8_t map[MEM_SIZE][4],
int position, t_ind *ind)
{
	(*ind).bytes[0] = map[(position + 1) % MEM_SIZE][0];
	(*ind).bytes[1] = map[position % MEM_SIZE][0];
}
