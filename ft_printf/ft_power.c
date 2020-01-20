/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:38:12 by bford             #+#    #+#             */
/*   Updated: 2019/10/03 18:31:28 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_power(int num, int power)
{
	unsigned long long	res;

	res = num;
	power--;
	while (power-- > 0)
		res *= num;
	return (res);
}
