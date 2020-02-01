/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:40:17 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 18:41:42 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	print_token_type(int i)
{
	if (i == NAME_TYPE)
		ft_putstr("NAME");
	else if (i == COMMENT_TYPE)
		ft_putstr("COMMENT");
	else if (i == NL_TYPE)
		ft_putstr("NEW LINE");
	else if (i == LABEL_TYPE)
		ft_putstr("LABEL");
	else if (i == DELIM_TYPE)
		ft_putstr("SEPARATOR");
	else if (i == OP_TYPE)
		ft_putstr("INSTRUCTION");
	else if (i == REG_ARG_TYPE)
		ft_putstr("REGISTER");
	else if (i == DIR_ARG_TYPE)
		ft_putstr("DIRECT ARG");
	else if (i == DIR_LABL_ARG_TYPE)
		ft_putstr("DIRECT LABEL");
	else if (i == IND_ARG_TYPE)
		ft_putstr("INDIRECT ARG");
	else if (i == IND_LABL_ARG_TYPE)
		ft_putstr("INDIRECT LABEL");
	else if (i == END_FILE)
		ft_putstr("END FILE");
}
