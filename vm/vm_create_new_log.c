/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create_new_log.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:11:19 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 19:23:28 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_create_new_log(char *file_name)
{
	int		fd;

	if ((fd = open(file_name, O_CREAT)) == -1)
		return (0);
	close(fd);
	return (1);
}
