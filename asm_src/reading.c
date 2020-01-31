/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:32:55 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 20:56:54 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		reading_helper_2(t_all *gen)
{
	if (is_op(gen))
		find_op(gen);
	else if (is_label(gen))
		find_label(gen);
	else if (is_reg_arg(&gen->file[gen->i]))
		find_reg_arg(gen);
	else if (is_dir_arg(&gen->file[gen->i]))
		find_dir_arg(gen);
	else if (is_dir_labl_arg(&gen->file[gen->i]))
		find_dir_labl_arg(gen);
}

void		reading_helper(t_all *gen)
{
	if (gen->file[gen->i] == COMMENT_CHAR || gen->file[gen->i] == ';')
		while (gen->file[gen->i] != '\n' && gen->file[gen->i])
			increment_point(gen);
	else if (!ft_strcmp(&gen->file[gen->i], ft_strstr(&gen->file[gen->i],
	NAME_CMD_STRING)))
		find_name_comment(gen, NAME_TYPE, NAME_CMD_STRING);
	else if (!ft_strcmp(&gen->file[gen->i], ft_strstr(&gen->file[gen->i],
	COMMENT_CMD_STRING)))
		find_name_comment(gen, COMMENT_TYPE, COMMENT_CMD_STRING);
	else if (gen->file[gen->i] == '\n' || gen->file[gen->i] == SEPARATOR_CHAR)
		find_nl_or_separ(gen);
	else if (is_op(gen) || is_label(gen) || is_reg_arg(&gen->file[gen->i]) ||
	is_dir_arg(&gen->file[gen->i]) || is_dir_labl_arg(&gen->file[gen->i]))
		reading_helper_2(gen);
	else if (is_ind_arg(&gen->file[gen->i]))
		find_ind_arg(gen);
	else if (is_ind_labl_arg(&gen->file[gen->i]))
		find_ind_labl_arg(gen);
	else
		reading_error(gen);
}

int			reading(t_all *gen)
{
	while (gen->file[gen->i])
	{
		while ((gen->file[gen->i] == ' ' || gen->file[gen->i] == '\t')
		&& gen->file[gen->i])
			increment_point(gen);
		if (!gen->file[gen->i])
			break ;
		reading_helper(gen);
	}
	push_tail_token(&gen->token, END_FILE, "END FILE", gen->point);
	return (0);
}
