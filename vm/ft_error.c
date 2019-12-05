/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:39:14 by bford             #+#    #+#             */
/*   Updated: 2019/12/05 17:39:59 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_error(int num, char *s)
{
	if (num == 1)
	{
		return (ft_putstr_fd("Error: invalid file: ", 2) + 
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
		return (ft_putstr_fd("Error: too many players\n", 2));
	else if (num == 8)
		return (ft_putstr_fd("Error: error in NULL bytes\n", 2));
	else if (num == 9)
		return (ft_putstr_fd("Error: error in exec code size bytes\n", 2));
	else if (num == 12)
		return (ft_putendl_fd("Error: memory error", 2));
	return (0);
}