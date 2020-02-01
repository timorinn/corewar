/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:52:13 by nsheev            #+#    #+#             */
/*   Updated: 2020/01/31 20:53:28 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

char		*get_op(char *s)
{
	if (!ft_strcmp(s, ft_strstr(s, "live")))
		return (ft_strdup("live"));
	else if (!ft_strcmp(s, ft_strstr(s, "ldi")))
		return (ft_strdup("ldi"));
	else if (!ft_strcmp(s, ft_strstr(s, "ld")))
		return (ft_strdup("ld"));
	else if (!ft_strcmp(s, ft_strstr(s, "sti")))
		return (ft_strdup("sti"));
	else if (!ft_strcmp(s, ft_strstr(s, "st")))
		return (ft_strdup("st"));
	else if (!ft_strcmp(s, ft_strstr(s, "add")))
		return (ft_strdup("add"));
	else if (!ft_strcmp(s, ft_strstr(s, "sub")))
		return (ft_strdup("sub"));
	else if (!ft_strcmp(s, ft_strstr(s, "and")))
		return (ft_strdup("and"));
	else
		return (get_op_helper(s));
}

void		find_op(t_all *gen)
{
	char	*tmp;
	int		j;

	tmp = get_op(&gen->file[gen->i]);
	j = ft_strlen(tmp);
	push_tail_token(&gen->token, OP_TYPE, tmp, gen->point);
	free(tmp);
	while (j)
	{
		increment_point(gen);
		j--;
	}
}

int			num_len(unsigned long num)
{
	int i;

	if (!num)
		return (1);
	i = 0;
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i);
}

int			is_reg_arg(char *s)
{
	int					i;
	unsigned long int	j;
	int					a;

	if ((s[0] != 'r') || (s[1] == '+' || s[1] == '-'
		|| !(s[1] <= '9' && s[1] >= '0')))
		return (0);
	i = 1;
	if (s[i] == '0')
		i++;
	a = i;
	while (ft_isdigit(s[a]))
		a++;
	if (a > 3)
		return (0);
	if (ft_isdigit(s[i]))
	{
		j = ft_atol(&s[i]);
		i += num_len(j);
		if (is_delim(s[i]) || s[i] == COMMENT_CHAR || s[i] == ';')
			return (1);
	}
	return (0);
}

void		find_reg_arg(t_all *gen)
{
	int		j;
	char	*tmp;

	j = gen->i + 1;
	while (gen->file[j] == '0')
		j++;
	j += num_len(ft_atol(&gen->file[j]));
	tmp = ft_strsub(gen->file, gen->i + 1, j - gen->i - 1);
	push_tail_token(&gen->token, REG_ARG_TYPE, tmp, gen->point);
	ft_strdel(&tmp);
	while (j > gen->i)
		increment_point(gen);
}
