/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_delete_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:35:48 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 19:38:32 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_delete_cursor(t_cursor *cur)
{
	int		size;
	int		i;

	i = 0;
	size = cur->size;
	while (i < size)
	{
		if (cur[i].file_name)
			free(cur[i].file_name);
		i++;
	}
	free (cur);
	return (0);
}
