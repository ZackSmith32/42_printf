/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_pi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/11 19:35:23 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void		p_func(conv_obj *obj, va_list args)
{
	void	*ptr;
	char	*ret;
	char	*holder;

	free(obj->str);
	ptr = va_arg(args, void *);
	if (ptr == 0 && obj->prec == 0)
		holder = ft_strdup("");
	else
		holder = ft_itoa_base((unsigned long long)ptr, 16);
	ret = (char *)ft_memalloc(ft_strlen(holder) + 3);
	ft_strcpy(ret, "0x\0");
	ft_strcat(ret, holder);
	free(holder);
	obj->str = ret;
	d_width(obj);
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