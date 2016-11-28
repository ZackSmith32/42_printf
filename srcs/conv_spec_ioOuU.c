/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_spec_ioOuU.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/27 13:26:54 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// #include "../includes/func_list.h"

void	i_func(conv_obj *obj, va_list args)
{
	d_func(obj, args);
	return ;
}

void	o_func(conv_obj *obj, va_list args)
{
	if (DEBUG_o) printf("o_func: in\n");
	int		n;

	star_args(obj);
	if (obj->con_typ == 'o')
		n = 8;
	else
		n = 16;
	if (!ft_strcmp(obj->len_f, "l") || !ft_strcmp(obj->len_f, "ll"))
		obj->str = ft_itoa_base(va_arg(args, unsigned long long), n);
	if (!ft_strcmp(obj->len_f, "j") || !ft_strcmp(obj->len_f, "z"))
		obj->str = ft_itoa_base(va_arg(args, unsigned long long), n);
	if (!ft_strcmp(obj->len_f, "hh") || !ft_strcmp(obj->len_f, "h")
		|| !ft_strlen(obj->len_f))
		obj->str = 
		ft_itoa_base((unsigned long long)va_arg(args, unsigned int), n);
	d_precision(obj);
	if (ft_strlen(obj->str) == 0)
		return ;
	d_precision(obj);
	o_hash(obj);
	x_hash(obj);
	d_width(obj);
	return ;
}

void	o_hash(conv_obj *obj)
{
	char	*new;

	if (!obj->hash || !(obj->con_typ == 'o'))
		return ;
	if ((obj->str)[0] == 0)
		return ;
	new = (char *)ft_memalloc(ft_strlen(obj->str) + 2);
	new[0] = '0';
	ft_strcpy(new + 1, obj->str);
	free(obj->str);
	obj->str = new;
}

void	x_hash(conv_obj *obj)
{
		char	*new;

	if (!obj->hash || !((obj->con_typ == 'x') || (obj->con_typ == 'X')))
		return ;
	if ((obj->str)[0] == 0)
		return ;
	new = (char *)ft_memalloc(ft_strlen(obj->str) + 3);
	new[0] = '0';
	new[1] = obj->con_typ;	
	ft_strcpy(new + 2, obj->str);
	free(obj->str);
	obj->str = new;
}

void	O_func(conv_obj *obj, va_list args)
{
	o_func(obj, args);
	return ;
}

void	u_func(conv_obj *obj, va_list args)
{
	d_func(obj, args);
	return ;
}

void	U_func(conv_obj *obj, va_list args)
{
	d_func(obj, args);
	return ;
}






















