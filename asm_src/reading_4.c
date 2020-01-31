/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:53:50 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 20:54:21 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_dir_arg(char *s)
{
	int i;

	if (s[0] != DIRECT_CHAR)
		return (0);
	i = 1;
	if (s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if ((is_delim(s[i]) || s[i] == COMMENT_CHAR || s[i] == ';')
	&& ft_isdigit(s[i - 1]))
		return (1);
	return (0);
}

void		find_dir_arg(t_all *gen)
{
	int		j;
	char	*tmp;

	j = gen->i + 1;
	while (gen->file[j] == ' ' || gen->file[j] == '\t')
		j++;
	if (gen->file[j] == '-')
		j++;
	while (ft_isdigit(gen->file[j]))
		j++;
	tmp = ft_strsub(gen->file, gen->i + 1, j - gen->i - 1);
	push_tail_token(&gen->token, DIR_ARG_TYPE, tmp, gen->point);
	ft_strdel(&tmp);
	while (j > gen->i)
		increment_point(gen);
}

int			is_dir_labl_arg(char *s)
{
	int i;

	if (s[0] != DIRECT_CHAR)
		return (0);
	i = 1;
	if (s[i] != LABEL_CHAR)
		return (0);
	i++;
	while (is_char_labl(s[i], LABEL_CHARS))
		i++;
	if (is_delim(s[i]) && is_char_labl(s[i - 1], LABEL_CHARS))
		return (1);
	return (0);
}

void		find_dir_labl_arg(t_all *gen)
{
	int		j;
	char	*tmp;
	int		start;

	j = gen->i + 1;
	while (gen->file[j] == ' ' || gen->file[j] == '\t')
		j++;
	start = ++j;
	while (is_char_labl(gen->file[j], LABEL_CHARS))
		j++;
	tmp = ft_strsub(gen->file, start, j - start);
	push_tail_token(&gen->token, DIR_LABL_ARG_TYPE, tmp, gen->point);
	free(tmp);
	while (j > gen->i)
		increment_point(gen);
}

int			is_ind_arg(char *s)
{
	int i;

	if (is_delim(s[0]))
		return (0);
	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i] == '0')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if ((is_delim(s[i]) || s[i] == COMMENT_CHAR || s[i] == ';') && i != 0)
		return (1);
	return (0);
}
