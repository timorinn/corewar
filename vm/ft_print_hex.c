/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:27:23 by bford             #+#    #+#             */
/*   Updated: 2019/12/06 14:52:30 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_print_hex(unsigned char c)
{
	write(1, &(HEX[c / 16 % 16]), 1);
	write(1, &(HEX[c % 16]), 1);
	return (1);
}
