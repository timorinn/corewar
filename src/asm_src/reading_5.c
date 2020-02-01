/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:55:24 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 20:56:55 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		find_ind_arg(t_all *gen)
{
	int		j;
	char	*tmp;
	int		start;

	j = gen->i;
	start = j;
	if (gen->file[j] == '-')
		j++;
	while (ft_isdigit(gen->file[j]))
		j++;
	tmp = ft_strsub(gen->file, start, j - start);
	push_tail_token(&gen->token, IND_ARG_TYPE, tmp, gen->point);
	free(tmp);
	while (j > gen->i)
		increment_point(gen);
}

int			is_ind_labl_arg(char *s)
{
	int i;

	if (s[0] != LABEL_CHAR)
		return (0);
	i = 1;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (is_char_labl(s[i], LABEL_CHARS))
		i++;
	if (is_delim(s[i]) && i > 1)
		return (1);
	return (0);
}

void		find_ind_labl_arg(t_all *gen)
{
	int		j;
	char	*tmp;
	int		start;

	j = gen->i + 1;
	while (gen->file[j] == ' ' || gen->file[j] == '\t')
		j++;
	start = j;
	while (is_char_labl(gen->file[j], LABEL_CHARS))
		j++;
	tmp = ft_strsub(gen->file, start, j - start);
	push_tail_token(&gen->token, IND_LABL_ARG_TYPE, tmp, gen->point);
	free(tmp);
	while (j > gen->i)
		increment_point(gen);
}

void		find_nl_or_separ(t_all *gen)
{
	char	*tmp;

	tmp = gen->file[gen->i] == '\n' ? char_to_string('\n') :
		char_to_string(SEPARATOR_CHAR);
	push_tail_token(&gen->token, gen->file[gen->i] == '\n' ? NL_TYPE :
		DELIM_TYPE, tmp, gen->point);
	free(tmp);
	increment_point(gen);
}

void		reading_error(t_all *gen)
{
	print_point(gen->point);
	ft_putstr(": Error: ");
	while (gen->file[gen->i] && gen->file[gen->i] != ' ' &&
		gen->file[gen->i] != '\t' && gen->file[gen->i] != '\n')
	{
		ft_putchar(gen->file[gen->i]);
		gen->i++;
	}
	write(1, "\n", 1);
	do_exit(NULL, gen);
}
