/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:32:09 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/05 20:04:16 by zsmith           ###   ########.fr       */
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
	newnew->prec = 0;
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
	{
		// if (DEBUG) printf("lstadd: holder->str = %s\n", holder->str);
		// if (DEBUG) printf("lstadd: holder->next = %p\n", holder->next);
		holder = holder->next;
	}
	holder->next = new;
}

void	test_print(conv_obj *obj)
{
	printf("*************************\n");
	if (obj->minus)
		printf("** minus  : %d\n", obj->minus);
	if (obj->plus)
		printf("** plus   : %d\n", obj->plus);
	if (obj->hash)
		printf("** hash   : %d\n", obj->hash);
	if (obj->space)
		printf("** space  : %d\n", obj->space);
	if (obj->zero)
		printf("** zero   : %d\n", obj->zero);
	printf("** len_f  : %s \n", obj->len_f);
	printf("** width  : %d\n", obj->width);
	if (obj->p_star)
		printf("** data_p_star : %d\n", obj->data_p_star);
	printf("** prec   : %d\n", obj->prec);
	if (obj->w_star)
		printf("** data_w_star : %d\n", obj->data_w_star);
	printf("** con_typ: %c\n", obj->con_typ);
	printf("** chr_cnt: %d\n", obj->chr_cnt);
	printf("** str    : %s\n", obj->str);
	if (obj->f)
		printf("** func   : yes\n");
	else
		printf("** func   : no\n");
	printf("*************************\n");

}

int		ft_putobj(conv_obj *t)
{
	if (DEBUG_LIST) printf("in: ft_putlist\n");
	if (DEBUG_LIST) printf("head str: %s\n", t->str);
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
		t = t->next;
		i++;
	}
	return (j);
}
