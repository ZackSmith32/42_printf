/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:32:09 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/16 12:44:28 by zsmith           ###   ########.fr       */
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
	newnew->hh = 0;
	newnew->h = 0;
	newnew->l = 0;
	newnew->ll = 0;
	newnew->j = 0;
	newnew->z = 0;
	newnew->width = 0;
	newnew->w_star = 0;
	newnew->prec = 0;
	newnew->p_star = 0;
	newnew->str = 0;
	return (newnew);
}

void		ft_lstadd_end(conv_obj *start, conv_obj *new)
{
	conv_obj	*holder;

	if (start == new)
		return ;
	holder = start;
	while (holder->next != NULL)
	{
		// printf("lstadd: holder->str = %s\n", holder->str);
		holder = holder->next;
	}
	holder->next = new;
}

void		ft_putlist(conv_obj *t)
{
	printf("in: ft_putlist\n");
	printf("head str: %s\n", t->str);
	int		i;

	if (!t)
		ft_putstr("*t = NULL\n");
	i = 0;
	while (t)
	{
		ft_putstr("[");
		ft_putstr(t->str);
		ft_putstr("/");
		ft_putnbr(t->plus);
		ft_putstr("/");
		ft_putnbr(t->width);
		ft_putstr("/");
		ft_putnbr(t->prec);
		ft_putstr("]");
		t = t->next;
		if (t)
			ft_putstr(" => ");
		i++;
	}
	ft_putstr("\n");
}
