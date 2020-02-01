/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:50:42 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 20:51:14 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		find_name_comment(t_all *gen, int type, char *command)
{
	int		j;
	int		j1;
	char	*tmp;
	char	*buf;

	j = gen->i + ft_strlen(command);
	while (gen->file[j] != '"' && (gen->file[j] == ' ' || gen->file[j] == '\t'))
		j++;
	if (gen->file[j] != '"' && (gen->error = ft_strdup("Name: Can't find \"")))
		do_exit(&gen->error, gen);
	tmp = ft_strsub(gen->file, j + 1, ft_strlen(gen->file) - j);
	buf = tmp;
	j1 = 0;
	while (buf[j1] != '"' && buf[j1])
		j1++;
	if (!buf[j1] && (gen->error = ft_strdup("End file in searching second \"")))
		do_exit(&gen->error, gen);
	tmp = ft_strsub(tmp, 0, j1);
	ft_strdel(&buf);
	push_tail_token(&gen->token, type, tmp, gen->point);
	ft_strdel(&tmp);
	j = j - gen->i + j1 + 2;
	while (j && (j-- || 1))
		increment_point(gen);
}

int			is_label(t_all *gen)
{
	int i;

	i = gen->i;
	if (gen->file[i] == LABEL_CHAR)
		return (0);
	while (is_char_labl(gen->file[i], LABEL_CHARS))
		i++;
	if (gen->file[i] == LABEL_CHAR)
		return (1);
	return (0);
}

int			find_label(t_all *gen)
{
	char	*tmp;
	int		j;

	j = gen->i;
	while (gen->file[j] != LABEL_CHAR)
		j++;
	tmp = ft_strsub(gen->file, gen->i, j - gen->i);
	push_tail_token(&gen->token, LABEL_TYPE, tmp, gen->point);
	ft_strdel(&tmp);
	while (j + 1 > gen->i)
		increment_point(gen);
	return (1);
}

int			is_op(t_all *gen)
{
	char	*s;

	s = &gen->file[gen->i];
	return ((!ft_strcmp(s, ft_strstr(s, "live")) && is_delop(s[4]) && s[4] !=
	LABEL_CHAR) || (!ft_strcmp(s, ft_strstr(s, "ld")) && is_delop(s[2]) && s[2]
	!= LABEL_CHAR) || (!ft_strcmp(s, ft_strstr(s, "st")) && is_delop(s[2]) &&
	s[2] != LABEL_CHAR) || (!ft_strcmp(s, ft_strstr(s, "add")) &&
	is_delop(s[3]) && s[3] != LABEL_CHAR) || (!ft_strcmp(s,
	ft_strstr(s, "sub")) && is_delop(s[3]) && s[3] != LABEL_CHAR) ||
	(!ft_strcmp(s, ft_strstr(s, "and")) && is_delop(s[3]) && s[3] !=
	LABEL_CHAR) || (!ft_strcmp(s, ft_strstr(s, "or")) && is_delop(s[2]) && s[2]
	!= LABEL_CHAR) || (!ft_strcmp(s, ft_strstr(s, "xor")) && is_delop(s[3]) &&
	s[3] != LABEL_CHAR) || (!ft_strcmp(s, ft_strstr(s, "zjmp")) &&
	is_delop(s[4]) && s[4] != LABEL_CHAR) || (!ft_strcmp(s,
	ft_strstr(s, "ldi")) && is_delop(s[3]) && s[3] != LABEL_CHAR) ||
	(!ft_strcmp(s, ft_strstr(s, "sti")) && is_delop(s[3]) && s[3] !=
	LABEL_CHAR) || (!ft_strcmp(s, ft_strstr(s, "fork")) && is_delop(s[4]) &&
	s[4] != LABEL_CHAR) || (!ft_strcmp(s, ft_strstr(s, "lld")) &&
	is_delop(s[3]) && s[3] != LABEL_CHAR) || (!ft_strcmp(s,
	ft_strstr(s, "lldi")) && is_delop(s[4]) && s[4] != LABEL_CHAR) ||
	(!ft_strcmp(s, ft_strstr(s, "lfork")) && is_delop(s[5]) && s[5] !=
	LABEL_CHAR) || (!ft_strcmp(s, ft_strstr(s, "aff")) && is_delop(s[3]) &&
	s[3] != LABEL_CHAR));
}

char		*get_op_helper(char *s)
{
	if (!ft_strcmp(s, ft_strstr(s, "or")))
		return (ft_strdup("or"));
	else if (!ft_strcmp(s, ft_strstr(s, "xor")))
		return (ft_strdup("xor"));
	else if (!ft_strcmp(s, ft_strstr(s, "zjmp")))
		return (ft_strdup("zjmp"));
	else if (!ft_strcmp(s, ft_strstr(s, "fork")))
		return (ft_strdup("fork"));
	else if (!ft_strcmp(s, ft_strstr(s, "lldi")))
		return (ft_strdup("lldi"));
	else if (!ft_strcmp(s, ft_strstr(s, "lld")))
		return (ft_strdup("lld"));
	else if (!ft_strcmp(s, ft_strstr(s, "lfork")))
		return (ft_strdup("lfork"));
	else if (!ft_strcmp(s, ft_strstr(s, "aff")))
		return (ft_strdup("aff"));
	return (NULL);
}
