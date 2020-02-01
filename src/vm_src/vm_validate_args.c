/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_validate_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:28:11 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 12:46:18 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

bool	vm_validate_args(t_args args, char const *validate, uint8_t max_args)
{
	uint8_t i;

	i = 0;
	while (i < max_args)
	{
		if ((args.types[i] == 0 && ft_strncmp(&validate[i * 3], "---", 3)) ||
		(args.types[i] == REG_CODE &&
		(validate[i * 3] == '-' || args.nums[i] < 1 || args.nums[i] > 16)) ||
		(args.types[i] == IND_CODE && validate[i * 3 + 1] == '-') ||
		(args.types[i] == DIR_CODE && validate[i * 3 + 2] == '-'))
			return (false);
		i++;
	}
	return (true);
}
