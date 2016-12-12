/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:52:51 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/11 19:18:00 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ret_null(conv_obj *obj)
{
	char	*a;

	a = ft_strdup("(null)");
	obj->str = a;
}

void	s_precision(conv_obj *obj, char *s)
{
	if (!s)
		return ;
	if (obj->prec != -1)
		ft_strncpy(obj->str, s, obj->prec);
	else
		ft_strcpy(obj->str, s);
}

void	s_func(conv_obj *obj, va_list args)
{
	char	*s;
	int		i;
	wchar_t	*w;

	free(obj->str);
	if (!ft_strcmp(obj->len_f, "l"))
	{
		w = va_arg(args, wchar_t *);
		if (w == NULL)
			return (ret_null(obj));
		s = (char *)ft_memalloc(utf_len(w));
		i = -1;
		while (w[++i] != 0)
			ft_strcat(s, s_wide(w[i]));
	}
	else 
	{
		s = va_arg(args, char *);
		if (s == NULL && obj->width == 0)
			return (ret_null(obj));
	}
	obj->str = (char *)ft_memalloc(ft_strlen(s) + 1);
	s_precision(obj, s);
	if (!ft_strcmp(obj->len_f, "l"))
		free(s);
	d_width(obj);
}

void	S_func(conv_obj *obj, va_list args)
{
	ft_strcpy(obj->len_f, "l");
	s_func(obj, args);
	return ;
}

void	c_func(conv_obj *obj, va_list args)
{
	int		d;
	char	*e;

	free(obj->str);
	d = -1;
	if (!ft_strcmp(obj->len_f, "l"))
	{
		obj->str = s_wide(va_arg(args, wint_t));
		if (obj->str[0] == 0)
			obj->extra += 1;
	}
	else
	{
		d = va_arg(args, int);
		if (d == 0)
			obj->extra += 1;
		e = (char *)ft_memalloc(2);
		e[0] = (char)d;
		e[1] = '\0';
		obj->str = e;
	}
	d_width(obj);
	if (d == 0)
		obj->str[obj->width - 1] = d;
}

void	C_func(conv_obj *obj, va_list args)
{
	ft_strcpy(obj->len_f, "l");
	c_func(obj, args);
	return ;
}












































