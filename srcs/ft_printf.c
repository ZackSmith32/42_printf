/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:26:23 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/19 18:29:14 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// #include "../includes/func_list.h"

/*
** need to create data structure param list
** need to create function for new param list (does mem need to be allocated)
** create fucntion that parses sentinel, and populates params
** advance sentinel
** TEST!!!!! 
*/



int		pop_obj(conv_obj *obj, char **sentinel, va_list args)
{
	printf("pop_obj:in: sentinel: %s\n", *sentinel);

	if (**sentinel == '%')
	{
		pop_flags(obj, sentinel);
		pop_width(obj, sentinel);
		pop_precision(obj, sentinel);
		pop_length(obj, sentinel);
		pop_con(obj, sentinel);
		pop_data(obj, args);
	} else {
		pop_str(obj, sentinel);
	}
	// printf("pop_obj: str: %s\n", obj->str);
	// printf("pop_obj: plus: %d\n", obj->plus);
	// (*sentinel)++;
	// increment_sent(obj);
	return (1);
}

void	con_hq(conv_obj *obj, va_list args)
{
	(obj->f)(obj);
}

char	*mission_control(char **sentinel, va_list args)
{
	// printf("mc:in: mission control\n");
	conv_obj	*item;
	conv_obj	*temp;

	item = new_conv_obj();
	temp = item;
	while (sentinel[0][0] != '\0')
	{
		// printf(">>>>>>>>>>>>>start\n");
		// printf("mc: sentinel: %s\n", *sentinel);
		if (temp_not_null(temp))
		{
			// printf("temp not null\n");
			temp  = new_conv_obj();
		}
		pop_obj(temp, sentinel, args);
		ft_lstadd_end(item, temp);
		// test_print(temp);
		// printf(">>>>>>>>>>>>>end\n\n");
	}
	// test_print(item);
	con_hq(item, args);
	printf("item->str: %s\n", item->str);

	return (0);
}

int		ft_printf(char *sentinel, ...)
{
	va_list args;
	int		x;

	va_start(args, sentinel);
	// x = (int)va_arg(args, void*);
	// printf("hello world%d\n", 5);
	// printf("ft_printf: va_args: %d\n", x);
	mission_control(&sentinel, args);
	va_end(args);

	return (0);
}

int		main(void)
{
	long long	z;
	int			y;

	z = -500;
	y = -500;
	// ft_printf("hello");
	// ft_printf("abcd %+++++10s", "hello");
	// ft_printf("foo %10.5s ++--  ");
	// ft_printf("hello world%-hhs% 14s%#19.31s%++-#s");
	// ft_printf("%hs");
	// ft_printf("%lls");
	// ft_printf("%ls");
	// ft_printf("%js");
	// ft_printf("%zs");
	ft_printf("%d", z);
	ft_printf("%d", y);
	// ft_printf("%s", "hello");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return (0);
}
