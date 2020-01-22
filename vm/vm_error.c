/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:39:14 by bford             #+#    #+#             */
/*   Updated: 2020/01/22 14:43:51 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int8_t		vm_error(int8_t num, char *s)
{
	if (num == 1)
	{
		return (ft_putstr_fd("Error: invalid champion file: ", 2) + 
		ft_putendl_fd(s, 2));
	}
	else if (num == 2)
		return (ft_putstr_fd("Error: invalid reading file\n", 2));
	else if (num == 3)
		return (ft_putstr_fd("Error: -n: not enough arguments\n", 2));
	else if (num == 4)
		return (ft_putstr_fd("Error: -n: invalid player number\n", 2));
	else if (num == 5)
		return (ft_putstr_fd("Error: -n: repeat player number\n", 2));
	else if (num == 6)
		return (ft_putstr_fd("Error: -dump: wrong number of cycles\n", 2));
	else if (num == 7)
		return (ft_putstr_fd("Error: too many champions\n", 2));
	else if (num == 8)
		return (ft_putstr_fd("Error: error in NULL bytes\n", 2));
	else if (num == 9)
		return (ft_putstr_fd("Error: error in exec code size bytes\n", 2));
	else if (num == 10)
		return (ft_putstr_fd("Error: wrong player number.\n", 2));
	else if (num == 11)
		return (ft_putstr_fd("Error: -n: repeat player number\n", 2));
	else if (num == 12)
		return (ft_putendl_fd("Error: memory error", 2));
	else if (num == 13)
		return (ft_putendl_fd("Error: flag log and flag visualization.\n", 2));
	return (0);
}