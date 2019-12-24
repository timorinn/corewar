/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:38:15 by kpsylock          #+#    #+#             */
/*   Updated: 2019/12/24 10:54:22 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	op_bitwise(uint8_t map[MEM_SIZE][4], t_cursor *car,
				   int32_t (*operation)(int32_t, int32_t))
{
	t_args 			args;

	ft_bzero(&args, sizeof(t_args));
	args.dir_size = 4;
	vm_get_args(map, car, &args);
	if (vm_validate_args(args, "RIDRIDR--"))
	{
		vm_unfold_all(map, car, &args, true);
		car->registr[args.nums[2]] = (*operation)
				(args.nums_unfolded[0], args.nums_unfolded[1]);
		car->carry = (car->registr[args.nums[2]] == 0 ? 1 : 0);
	}
	car->position += ft_move(args.types, "1110", 4) + 2;
	car->position %= MEM_SIZE;
	return (true);
}