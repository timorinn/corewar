/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lstdel_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:23:45 by bford             #+#    #+#             */
/*   Updated: 2020/01/05 16:25:00 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_lstdel_cursor(t_cursor *cursor)
{
	t_cursor	*copy;

	while (cursor)
	{
		copy = cursor;
		cursor = cursor->next;
		free(copy);
	}
}
