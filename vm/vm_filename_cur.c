/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_filename_cur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:36:03 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 19:24:31 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*vm_filename_cur(int num)
{
	char	*file_name;
	char	*nbr_file;

	if (!(nbr_file = ft_itoa(num)))
		return (NULL);
	if (!(file_name = ft_strjoin("logs/", nbr_file)))
		return (NULL + ft_strdel(&nbr_file));
	return (file_name + ft_strdel(&nbr_file));
}