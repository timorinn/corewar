/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:39:14 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 14:18:55 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int8_t		vm_error2(int8_t num)
{
	if (num == 10)
		return (ft_putendl_fd("Error: wrong player number.", 2));
	else if (num == 11)
		return (ft_putendl_fd("Error: -n: repeat player number.", 2));
	else if (num == 12)
		return (ft_putendl_fd("Error: memory error", 2));
	else if (num == 13)
		return (ft_putendl_fd("Error: flag log and flag visualization.", 2));
	return (0);
}

int8_t		vm_error(int8_t num, const char *s)
{
	if (num == 1)
		return (ft_putstr_fd("Error: invalid champion file: ", 2) +
		ft_putendl_fd(s, 2));
	else if (num == 2)
		return (ft_putendl_fd("Error: invalid reading file.", 2));
	else if (num == 3)
		return (ft_putendl_fd("Error: -n: not enough arguments.", 2));
	else if (num == 4)
		return (ft_putendl_fd("Error: -n: invalid player number.", 2));
	else if (num == 5)
		return (ft_putendl_fd("Error: -n: repeat player number.", 2));
	else if (num == 6)
		return (ft_putendl_fd("Error: -dump: wrong number of cycles.", 2));
	else if (num == 7)
		return (ft_putendl_fd("Error: too many champions.", 2));
	else if (num == 8)
		return (ft_putendl_fd("Error: error in NULL bytes.", 2));
	else if (num == 9)
		return (ft_putendl_fd("Error: error in exec code size bytes.", 2));
	return (vm_error2(num));
}
