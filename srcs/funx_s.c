/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:52:51 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 23:26:41 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	s_func(conv_obj *obj, va_list args)
{
	char	*s;
	int		i;
	wchar_t	*w;

	free(obj->str);
	if (!ft_strcmp(obj->len_f, "l"))
	{
		w = va_arg(args, wchar_t *);
		s = (char *)ft_memalloc(utf_len(w));
		i = -1;
		while (w[++i] != 0)
			ft_strcat(s, s_wide(w[i]));
	}
	else 
		s = va_arg(args, char *);
	obj->str = (char *)malloc(ft_strlen(s) + 1);
	if (obj->prec != -1)
		ft_strncpy(obj->str, s, obj->prec);
	else
		ft_strcpy(obj->str, s);
	if (!ft_strcmp(obj->len_f, "l"))
		free(s);
	d_width(obj);
}

void	S_func(conv_obj *obj, va_list args)
{
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
		obj->str = s_wide(va_arg(args, wint_t));
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
	c_func(obj, args);
	return ;
}












































