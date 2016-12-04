/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:52:51 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/04 13:01:35 by zsmith           ###   ########.fr       */
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


char	*s_wide(wchar_t *wide)
{
	if (DEBUG_s) printf("s_wide: in\n");
	char		*ret;
	char		*temp;
	int			i;

	ret = (char *)ft_memalloc(utf_len(wide) + 1);
	i = 0;
	while (wide[i] != 0)
	{
		if (wide[i] <= 0x78)
			temp = s_wide_1(wide[i]);
		else if (wide[i] <= 0x1fff)
			temp = s_wide_2(wide[i]);
		else if (wide[i] <= 0xffff)
			temp = s_wide_3(wide[i]);
		else
			temp = s_wide_4(wide[i]);
		ft_strcat(ret, temp);
		ft_bzero(temp, ft_strlen(temp));
		free(temp);
		i++;
	}
	ft_strcat(ret, "\0");
	return (ret);
	if (DEBUG_s) printf("\ns_wide: ret = %s\n", ret);
}


void	s_func(conv_obj *obj, va_list args)
{
	if (DEBUG_s) printf("s_func: in\n");
	char	*s;
	int		i;

	if (!ft_strcmp(obj->len_f, "l"))
	{
		while ()
		{
			s = s_wide(va_arg(args, wchar_t *));
		}
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
	printf("s_func: obj->str = %s\n", obj->str);
}

void	S_func(conv_obj *obj, va_list args)
{
	s_func(obj, args);
	return ;
}

void	c_func(conv_obj *obj, va_list args)
{
	if (DEBUG_c) printf("c_func: in\n");
	int		c;
	char	d;
	int		*str;

	if (!ft_strcmp(obj->len_f, "l"))
	{
		c = va_arg(args, wint_t);
		// str = ft_memalloc(sizeof(int));
		// str = &c;
		printf("%u\n", c);
		printf("result: ");
		write(1, &c, 2);
		printf("\n");
	}
	// else
	// {
	// 	d = va_arg(args, char);
	// 	str = ft_memalloc(1);
	// }
}

void	C_func(conv_obj *obj, va_list args)
{
	return ;
}


// \xF0\x9F\x93\xBA 