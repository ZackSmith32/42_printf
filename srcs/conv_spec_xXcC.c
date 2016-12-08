/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_spec_xXcC.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/07 10:07:03 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_func(conv_obj *obj, va_list args)
{
	if (DEBUG_o) printf("in x_func\n");

	o_func(obj, args);
}

void	X_func(conv_obj *obj, va_list args)
{
	if (DEBUG_o) printf("in X_func\n");
	int		i;

	o_func(obj, args);
	if (DEBUG_o) printf("X_func: after o_func: str: %s\n", obj->str);
	i = 0;
	while ((obj->str)[i])
	{
		obj->str[i] = ft_toupper((obj->str)[i]);
		i++;
	}
	return ;
}

void		p_func(conv_obj *obj, va_list args)
{
	void	*ptr;
	char	*ret;

	ptr = va_arg(args, void *);
	ret = (char *)ft_memalloc(ft_strlen(ptr) + 3);
	ft_strcpy(ret, "0x\0");
	ft_strcat(ret, ft_itoa_base((unsigned long long)ptr, 16));
	obj->str = ret;
}

void		non_func(conv_obj *obj, va_list args)
{
	if (obj->w_star)
		obj->width = va_arg(args, int);
	obj->str = ft_strdup("%");
	d_width(obj);
}