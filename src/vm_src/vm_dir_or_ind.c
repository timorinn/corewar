/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_dir_or_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:59:37 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 13:51:40 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int8_t	vm_dir_or_ind(unsigned int arg, int8_t tdir)
{
	if (arg == DIR_CODE)
		return (tdir);
	else if (arg == IND_CODE)
		return (IND_SIZE);
	else if (arg == REG_CODE)
		return (1);
	return (0);
}
