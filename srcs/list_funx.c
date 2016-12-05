/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:32:09 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/04 22:40:13 by zsmith           ###   ########.fr       */
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

void		ft_putobj(conv_obj *t)
{
	printf("in: ft_putlist\n");
	printf("head str: %s\n", t->str);
	int		i;
	char	*hld;

	if (!t)
		ft_putstr("*t = NULL\n");
	i = 0;
	while (t)
	{
		// printf("in while");
		// printf("%s", t->str);
		// ft_putstr("[");
		hld = t->str;
		ft_putstr("wtf?");
		// ft_putstr("/");
		// ft_putnbr(t->plus);
		// ft_putstr("/");
		// ft_putnbr(t->width);
		// ft_putstr("/");
		// ft_putnbr(t->prec);
		ft_putstr("]");
		t = t->next;
		if (t)
			ft_putstr(" => ");
		i++;
	}
	ft_putstr("\n");
}
