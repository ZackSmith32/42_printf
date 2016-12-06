/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:36:17 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/05 19:03:02 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	D_func(conv_obj *obj, va_list args)
{
	obj->len_f = "l";
	d_func(obj, args);
	return ;
}

void	d_func(conv_obj *obj, va_list args)
{
	star_args(obj, args);
	if (DEBUG_D) printf("d_func: in: obj->len_f = |%s|\n", obj->len_f);
	if (obj->w_star)
		obj->width = va_arg(args, int);
	if (obj->p_star)
		obj->prec = va_arg(args, int);
	if (!ft_strcmp(obj->len_f, "hh")
			|| !ft_strcmp(obj->len_f, "h")
			|| !ft_strlen(obj->len_f))
	{
		if (DEBUG_D) printf("obj->len_f = hh\n");
		obj->str = ft_itoa3((long long)va_arg(args, int));
		if (DEBUG_D) printf("obj-str = %s\n", obj->str);
	}
	if (!ft_strcmp(obj->len_f, "l")
			|| !ft_strcmp(obj->len_f, "ll"))
	{
		if (DEBUG_D) printf("obj->len_f = ll\n");
		obj->str = ft_itoa3(va_arg(args, long long));
		if (DEBUG_D) printf("obj-str = %s\n", obj->str);		
	}
	if (!ft_strcmp(obj->len_f, "j")
		|| !ft_strcmp(obj->len_f, "z"))
	{
		if (DEBUG_D) printf("obj->len_f = j/z\n");
		obj->str = ft_itoa3(va_arg(args, unsigned long long));
	}
	d_precision(obj);
	plus_func(obj);
	space_flag(obj);
	if (ft_strlen(obj->str) == 0)
		return ;
	d_width(obj);
	return ;
}

void	d_precision(conv_obj *obj)
{
	char	*new_str;
	char	*holder;
	int		diff;

	if (ft_atoi(obj->str) == 0 && obj->prec == 0)
	{
		obj->str = ft_memalloc(1);
		return ;
	}
	diff = obj->prec - ft_strlen(obj->str);
	if (diff <= 0)
		return ;
	new_str = ft_memalloc(obj->prec);
	ft_memset(new_str, 48, (size_t)(obj->prec + 1));
	holder = new_str + diff;
	ft_strcpy(holder, obj->str);
	free(obj->str);
	obj->str = new_str;	
}

/*
	if (!minus) 
		then start copy into new string starting in the middle such that the result is right justification
	else
		start the copy at the beginning (left justified)		 
*/
void	d_width(conv_obj *obj)
{
	if (DEBUG_D) printf("width: in\n");
	char	*new_str;
	char	*holder;
	int		diff;

	diff = obj->width - ft_strlen(obj->str);
	if (diff > 0)
	{
		new_str = ft_memalloc(obj->width + 1);
		ft_memset(new_str, obj->zero ? 48 : 32, (size_t)(obj->width));
		if (DEBUG_D) printf("width: in: after memset\n");
		if (!obj->minus)
			holder = new_str + diff;
		else
			holder = new_str;
		if (DEBUG_D) printf("width: holder\n");

		ft_strncpy(holder, obj->str, ft_strlen(obj->str));
		free(obj->str);
		obj->str = new_str;
	}
}

