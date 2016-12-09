/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_pi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/09 13:37:17 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void		p_func(conv_obj *obj, va_list args)
{
	void	*ptr;
	char	*ret;

	free(obj->str);
	ptr = va_arg(args, void *);
	ret = (char *)ft_memalloc(ft_strlen(ptr) + 3);
	ft_strcpy(ret, "0x\0");
	ft_strcat(ret, ft_itoa_base((unsigned long long)ptr, 16));
	obj->str = ret;
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
	obj->str = ft_strdup("%");
	d_width(obj);
}