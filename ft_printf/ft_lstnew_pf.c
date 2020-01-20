/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:54:12 by bford             #+#    #+#             */
/*   Updated: 2019/10/01 15:26:03 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_pf	*ft_lstnew_pf(void)
{
	t_pf *l;

	if (!(l = (t_pf *)malloc(sizeof(t_pf))))
		return (0);
	l->m = 0;
	l->p = 0;
	l->o = 0;
	l->s = 0;
	l->nol = 0;
	l->i1 = 0;
	l->i1was = 0;
	l->point = 0;
	l->i2 = 0;
	l->i2was = 0;
	l->f = 0;
	l->c = 0;
	l->all = 0;
	return (l);
}
