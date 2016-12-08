/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:52:00 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 10:55:40 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	o_hash(conv_obj *obj)
{
	char	*new;

	if (!obj->hash || !(obj->con_typ == 'o'))
		return ;
	new = (char *)ft_memalloc(ft_strlen(obj->str) + 2);
	new[0] = '0';
	ft_strcpy(new + 1, obj->str);
	free(obj->str);
	obj->str = new;
}

void	o_func(conv_obj *obj, va_list args)
{
	int		n;
	unsigned long	check;

	star_args(obj, args);
	if (obj->con_typ == 'o')
		n = 8;
	else
		n = 16;
	if (!ft_strcmp(obj->len_f, "l") || !ft_strcmp(obj->len_f, "ll"))
		obj->str = ft_itoa_base(va_arg(args, unsigned long long), n);
	if (!ft_strcmp(obj->len_f, "j") || !ft_strcmp(obj->len_f, "z"))
	{
		check = va_arg(args, unsigned long);
		obj->str = ft_itoa_base(check, n);
	}
	if (!ft_strcmp(obj->len_f, "hh") || !ft_strcmp(obj->len_f, "h")
		|| !ft_strlen(obj->len_f))
		obj->str = ft_itoa_base(va_arg(args, unsigned int), n);
	if (ft_strlen(obj->str) == 0)
		return ;
	d_precision(obj);
	o_hash(obj);
	x_hash(obj);
	d_width(obj);
	x_hash_alt(obj);
}

void	O_func(conv_obj *obj, va_list args)
{
	o_func(obj, args);
	return ;
}
