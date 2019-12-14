/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_or_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:59:37 by bford             #+#    #+#             */
/*   Updated: 2019/12/14 22:18:02 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_dir_or_ind(unsigned int arg, int tdir)
{
	if (arg == DIR_CODE)
		return (tdir);
	else if (arg == IND_CODE)
		return (IND_SIZE);
	else if (arg == REG_CODE )
		return (1);
	return (0);
}
