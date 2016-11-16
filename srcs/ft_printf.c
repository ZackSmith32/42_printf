/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:26:23 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/15 22:44:24 by zsmith           ###   ########.fr       */
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
	} else {
		pop_str(obj, sentinel);
	}
	// printf("pop_obj: str: %s\n", obj->str);
	// printf("pop_obj: plus: %d\n", obj->plus);
	// (*sentinel)++;
	// increment_sent(obj);
	return (1);
}

char	*mission_control(char **sentinel, va_list args)
{
	printf("mc:in: mission control\n");
	conv_obj	*item;
	conv_obj	*temp;

	item = new_conv_obj();
	temp = item;
	while (sentinel[0][0] != '\0')
	{
		printf(">>>>>>>>>>>>>start\n");
		printf("mc: sentinel: %s\n", *sentinel);
		if (temp_not_null(temp))
		{
			printf("temp not null\n");
			temp  = new_conv_obj();
		}
		pop_obj(temp, sentinel, args);
		ft_lstadd_end(item, temp);
		test_print(temp);
		printf(">>>>>>>>>>>>>end\n\n");
	}
	// printf("mc:");
	// ft_putlist(item);
	return (0);
}

int		ft_printf(char *sentinel, ...)
{
	va_list args;

	va_start(args, sentinel);
	mission_control(&sentinel, args);
	va_end(args);

	return (0);
}

int		main(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	// ft_printf("hello");
	// ft_printf("abcd %+++++10s", "hello");
	// ft_printf("foo %10.5s ++--  ");
	ft_printf("%-hhs% 14s%#19.31s%++-#s");
	// ft_printf("%hs");
	// ft_printf("%lls");
	// ft_printf("%ls");
	// ft_printf("%js");
	// ft_printf("%zs");

	// ft_printf("%s", "hello");
	return (0);
}
