/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:35:25 by kpsylock          #+#    #+#             */
/*   Updated: 2019/12/24 10:54:22 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static int32_t op_xor(int32_t first, int32_t second)
{
	return (first ^ second);
}

bool	vm_op_xor(uint8_t map[MEM_SIZE][4], t_cursor *car)
{
	return (vm_op_bitwise(map, car, &op_xor));

}