/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_delete_logs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:47:11 by bford             #+#    #+#             */
/*   Updated: 2019/12/28 17:56:08 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_delete_logs(void)
{
	DIR				*logs;
	struct dirent	*file;	
	int				i;

	i = 0;
	logs = opendir("logs");
	if (!logs)
	{
		printf("XyeBa\n");
		return ;
	}
	while ((file = readdir(logs)) && ++i)
	{
		//i > 2 ? printf("File for delete #%d   %s\n", i - 2, file->d_name) : 0;
		// remove(file->d_name); // УДАЛЕНИЕ ФАЙЛОВ
	}
}
