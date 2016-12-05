/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:52:51 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/04 22:11:44 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*s_wide_1(int wc)
{
	if (DEBUG_s) printf("s_wide_1: in\n");
	char		*ret;

	ret = (char *)ft_memalloc(2);
	ret[0] = wc;
	ret[1] = '\0';
	return (ret);
}
char	*s_wide_2(int wc)
{
	if (DEBUG_s) printf("s_wide_2: in\n");
	char 		*ret;

	ret = (char *)ft_memalloc(3);
	ret[1] = (wc & 0x3f) | 0x80;
	ret[0] = (wc >> 6 & 0x1f) | 0xc0;
	ret[2] = '\0';
	return (ret);
}

char 	*s_wide_3(int wc)
{
	if (DEBUG_s) printf("s_wide_3: in\n");
	char		*ret;

	ret = (char *)ft_memalloc(4);
	ret[2] = (wc & 0x3f) | 0x80;
	ret[1] = (wc >> 6 & 0x3f) | 0x80;
	ret[0] = (wc >> 12 & 0x0f) | 0xe0;
	ret[3] = '\0';
	return (ret);
}

char	*s_wide_4(int wc)
{
	if (DEBUG_s) printf("s_wide_4: in\n");
	char		*ret;

	ret = (char *)ft_memalloc(5);
	ret[3] = (wc & 0x3f) | 0x80;
	ret[2] = (wc >> 6 & 0x3f) | 0x80;
	ret[1] = (wc >> 12 & 0x3f) | 0x80;
	ret[0] = (wc >> 18 & 0x07) | 0xf0;
	ret[4] = '\0';
	return (ret);
}


char	*s_wide(wchar_t wide)
{
	if (DEBUG_s) printf("s_wide: in\n");
	char		*ret;
	int			i;

	if (wide <= 0x78)
		ret = s_wide_1(wide);
	else if (wide <= 0x1fff)
		ret = s_wide_2(wide);
	else if (wide <= 0xffff)
		ret = s_wide_3(wide);
	else
		ret = s_wide_4(wide);
	ft_strcat(ret, "\0");
	if (DEBUG_s) printf("\ns_wide: ret = %s\n", ret);
	return (ret);
}


void	s_func(conv_obj *obj, va_list args)
{
	if (DEBUG_s) printf("s_func: in\n");
	char	*s;
	int		i;
	wchar_t	*w;

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
	if (obj->prec)
		ft_strncpy(obj->str, s, obj->prec);
	else
		ft_strcpy(obj->str, s);
	if (!ft_strcmp(obj->len_f, "l"))
		free(s);
	d_width(obj);
	if (DEBUG_s) printf("s_func: obj->str = %s\n", obj->str);
}

void	S_func(conv_obj *obj, va_list args)
{
	s_func(obj, args);
	return ;
}

void	c_func(conv_obj *obj, va_list args)
{
	if (DEBUG_c) printf("c_func: in\n");
	char	*d;

	if (!ft_strcmp(obj->len_f, "l"))
		d = s_wide(va_arg(args, wint_t));
	else
	{
		d = (char *)ft_memalloc(2);
		d[0] = va_arg(args, int);
		d[1] = '\0';
	}
	obj->str = d;
}

void	C_func(conv_obj *obj, va_list args)
{
	c_func(obj, args);
	return ;
}


// \xF0\x9F\x93\xBA 










































