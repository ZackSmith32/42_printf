/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_pi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/12 16:46:38 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		p_precision(conv_obj *obj)
{
	// printf("p_prec: in: prec = %d\n", obj->prec);
	char	*holder;
	int		sz;

	if (obj->prec == -1)
		return ;

	if (obj->prec < (int)ft_strlen(obj->str) + 2)
		sz = ft_strlen(obj->str) + 3;
	else
		sz = obj->prec + 3;
	// printf("%d\n", sz);
	holder = (char *)ft_memalloc(sz);
	ft_memset(holder, '0', sz - 1);
	holder[1] = 'x';
	// printf("holder 1 = >%s<\n", holder);
	ft_strcpy(holder + (sz - 1 - ft_strlen(obj->str)), obj->str);
	// printf("holder 2 = >%s<\n", holder);
	free(obj->str);
	obj->str = holder;
	// free(holder); << I really think that I need to free this???
}

void		p_width(conv_obj *obj)
{
	char	*s;

	if (obj->zero == 1)
	{
		obj->prec = obj->width - 2;
		p_precision(obj);
		return ;
	}
	if (obj->prec == -1)
	{
		obj->prec = 0;
		// printf("p_width: in if: obj->str = >%s<\n", obj->str);
		// printf("strlen(str) = %d\n", (int)ft_strlen(obj->str));
		p_precision(obj);
	}
	// printf("obj->width = %d\n", (int)ft_strlen(obj->str));
	if ((obj->width - (int)ft_strlen(obj->str)) <= 0)
		return ;
	s = (char *)ft_memalloc(obj->width + 1);
	ft_memset(s, ' ', obj->width);
	// printf("p_width: str = >%s<\n", s);
	if (obj->minus == 1)
		ft_strncpy(s, obj->str, ft_strlen(obj->str));
	else 
		ft_strcpy(s + (obj->width - ft_strlen(obj->str)), obj->str);
	free(obj->str);
	obj->str = s;
}

void		p_func(conv_obj *obj, va_list args)
{
	// printf("prec = %d\n", obj->prec);
	void	*ptr;

	free(obj->str);
	ptr = va_arg(args, void *);
	obj->str = ft_itoa_base((unsigned long long)ptr, 16);
	if (obj->prec == 0 && ft_strcmp(obj->str, "0") == 0)
	{
 		free(obj->str);
		obj->str = ft_strdup("0x");
	}
	else 
		p_precision(obj);
	p_width(obj);
	// printf("after:>%s<\n", obj->str);
}

void	i_func(conv_obj *obj, va_list args)
{
	d_func(obj, args);
	return ;
}

void		non_func(conv_obj *obj, va_list args)
{
	if (obj->w_star)
		obj->width = va_arg(args, int);
	free(obj->str);
	obj->str = ft_strdup(&obj->con_typ);
	d_width(obj);
}