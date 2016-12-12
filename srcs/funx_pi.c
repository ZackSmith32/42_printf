/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_pi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/11 22:19:35 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void p_precision(conv_obj *obj)
{
	char	*new_str;
	char	*holder;
	int		diff;

	if (!ft_strcmp(obj->str, "0") && obj->prec == 0)
	{
		free(obj->str);
		obj->str = ft_memalloc(1);
		return ;
	}
	diff = obj->prec - ft_strlen(obj->str);
	if (diff <= 0)
		return ;
	new_str = (char *)ft_memalloc(obj->prec);
	ft_memset(new_str, 48, (size_t)(obj->prec + 1));
	holder = new_str + diff;
	ft_strcpy(holder, obj->str);
	free(obj->str);
	obj->str = new_str;
}

static void p_width(conv_obj *obj)
{
	char	*new_str;
	char	*holder;
	int		diff;

	diff = obj->width - 2 - ft_strlen(obj->str);
	if (diff > 0)
	{
		new_str = (char *)ft_memalloc(obj->width + 1 - 2);
		ft_memset(new_str, obj->zero == 1 ? 48 : 32, (size_t)(obj->width) - 2);
		if (!obj->minus)
			holder = new_str + diff;
		else
			holder = new_str;
		ft_strncpy(holder, obj->str, ft_strlen(obj->str));
		free(obj->str);
		obj->str = new_str;
		if (obj->zero == 1 && (obj->con_typ == 'd' || obj->con_typ == 'D') &&
			(obj->plus == 1 || ft_strchr(obj->str, '-')))
			d_width_zero(obj);
	}
}

void		p_func(conv_obj *obj, va_list args)
{
	void	*ptr;
	char	*ret;

	free(obj->str);
	ptr = va_arg(args, void *);
	// if (ptr == 0 && obj->prec == 0)
	// 	holder = ft_strdup("");
	// else
	obj->str = ft_itoa_base((unsigned long long)ptr, 16);
	p_precision(obj);
	p_width(obj);
	ret = (char *)ft_memalloc(ft_strlen(obj->str) + 3);
	ft_strcpy(ret, "0x\0");
	ft_strcat(ret, obj->str);
	free(obj->str);
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
	obj->str = ft_strdup(&obj->con_typ);
	d_width(obj);
}