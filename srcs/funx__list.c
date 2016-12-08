/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:32:09 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 12:37:57 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

conv_obj	*new_conv_obj(void)
{
	conv_obj	*newnew;

	newnew = (conv_obj *)malloc(sizeof(conv_obj));
	newnew->minus = 0;
	newnew->plus = 0;
	newnew->hash = 0;
	newnew->space = 0;
	newnew->zero = 0;
	newnew->len_f = "\0";
	newnew->width = 0;
	newnew->w_star = 0;
	newnew->extra = 0;
	newnew->prec = -1;
	newnew->p_star = 0;
	newnew->con_typ = 0;
	newnew->str = 0;
	newnew->next = 0;
	return (newnew);
}

void		ft_lstadd_end(conv_obj *start, conv_obj *new)
{
	conv_obj	*holder;

	if (start == new)
		return ;
	holder = start;
	while (holder->next != NULL)
		holder = holder->next;
	holder->next = new;
}

int		ft_putobj(conv_obj *t)
{
	int		i;
	int		j;

	if (!t)
		ft_putstr("*t = NULL\n");
	i = 0;
	j = 0;
	while (t)
	{
		ft_putstr(t->str);
		j += ft_strlen(t->str);
		if (t->extra == 1)
			j++;
		t = t->next;
		i++;
	}
	return (j);
}
