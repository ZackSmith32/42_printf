/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:56:21 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 20:01:10 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	u_func(conv_obj *obj, va_list args)
{
	star_args(obj, args);
	free(obj->str);
	if (!ft_strcmp(obj->len_f, "hh"))
		obj->str = ft_itoa_base((unsigned char)va_arg(args, unsigned int), 10);
	if (!ft_strcmp(obj->len_f, "h"))
		obj->str = ft_itoa_base(
			(unsigned short)va_arg(args, unsigned int), 10);
	if (!ft_strlen(obj->len_f))
		obj->str = ft_itoa_base(va_arg(args, unsigned int), 10);
	if (!ft_strcmp(obj->len_f, "l")
			|| !ft_strcmp(obj->len_f, "ll"))
		obj->str = ft_itoa_base(
			(unsigned long)va_arg(args, unsigned long long), 10);
	if (!ft_strcmp(obj->len_f, "j")
		|| !ft_strcmp(obj->len_f, "z"))
		obj->str = ft_itoa_base(va_arg(args, unsigned long long), 10);
	d_precision(obj);
	if (ft_strlen(obj->str) == 0)
		return ;
	d_width(obj);
	return ;
}

void	U_func(conv_obj *obj, va_list args)
{
	ft_strcpy(obj->len_f, "l");
	u_func(obj, args);
	return ;
}

