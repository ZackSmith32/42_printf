/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:32:09 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 23:56:42 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

conv_obj	*new_conv_obj(void)
{
	conv_obj	*newnew;

	newnew = (conv_obj *)ft_memalloc(sizeof(conv_obj));
	newnew->len_f = (char *)ft_memalloc(2);
	newnew->prec = -1;
	newnew->str = ft_strdup("*");
	printf("addy= %p\n", (newnew->str));
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
	int			i;
	int			j;
	conv_obj	*k;

	if (!t)
		ft_putstr("*t = NULL\n");
	i = 0;
	j = 0;
	while (t)
	{
		// ft_putstr("\n\n");
		ft_putstr(t->str);
		// ft_putstr("\n\n");
		j += ft_strlen(t->str);
		if (t->extra == 1)
			j++;
		k = t;
		// printf("free: %p\n\n", t->len_f);
		free(t->len_f);
		free(t->str);
		t = t->next;
		free(k);
		i++;
	}
	free(t);
	return (j);
}
