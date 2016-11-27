/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:26:23 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/27 11:57:16 by zsmith           ###   ########.fr       */
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


/*
** all the pop funcitons return sentinel pointing at the next char to analyze
*/
int		pop_obj(conv_obj *obj, char **sentinel, va_list args)
{
	if (DEBUG) printf("pop_obj: in : sentinel = %s\n", *sentinel);

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
	// printf("pop_obj: con_typ = %c\n", obj->con_typ);
	// printf("pop_obj: n: %d\n", obj->n);
	if (DEBUG) printf("pop_obj: out: sentinel = %s\n", *sentinel);
	return (1);
}

void	con_hq(conv_obj *obj, va_list args)
{
	// obj->f = &d_func;
	if (DEBUG) printf("con_hq: in\n");
	if (obj->f)
	{
		if (DEBUG) printf("con_hq: obj->f exists\n");
		(obj->f)(obj, args);
	}
}

char	*mission_control(char **sentinel, va_list args)
{
	if (DEBUG) printf("mc: in:\n");
	conv_obj	*item;
	conv_obj	*temp;

	item = new_conv_obj();
	temp = item;
	while (sentinel[0][0] != '\0')
	{
		if (DEBUG) printf(">>>>>>>>>>>>>start\n");
		if (1) printf("mc: sentinel: %s\n", *sentinel);
		if (temp_not_null(temp))
		{
			// printf("temp not null\n");
			temp  = new_conv_obj();
		}
		pop_obj(temp, sentinel, args);
		con_hq(temp, args);
		test_print(temp);
		ft_lstadd_end(item, temp);
		if (DEBUG) printf(">>>>>>>>>>>>>end\n\n");
	}
	// test_print(item);
	// printf("mc: temp->str: %s\n", temp->str);

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
	/*
	signed char	q = -100;
	short		r = -200;
	int			s = -300;
	long		t = -400;
	long long	u = -3147483648;
	intmax_t	v = -600;
	size_t		w = 700;

	unsigned long long u; 
	u = 10223372036854775807;
	intmax_t	v = 10223372036854775807;
	size_t		w = 10223372036854775807;
	*/
	/* length modifier testing *//*
	ft_printf("%8hhd", q);
	ft_printf("%8hd", r);
	ft_printf("%8d", s);
	ft_printf("%8ld", t);
	ft_printf("%8lld", u);
	ft_printf("%8jd", v);
	ft_printf("% +8zd", w);
	*/
	/* precision and width testing */
	ft_printf("%#llx", (unsigned long long)27);

	printf("** printf : ");
	printf("%#llX\n", (unsigned long long)27);


	// ft_printf("signed char:%hhd", q);
	// ft_printf("short      :%hd", r);

	// ft_printf("long       :%ld", t);
	// ft_printf("long long  :%lld", u);
	// ft_printf("intmax_t   :%jd", v);
	// ft_printf("size_t     :%zd", w);







	// ft_printf("hello");
	// ft_printf("abcd %+++++10s", "hello");
	// ft_printf("foo %10.5s ++--  ");
	// ft_printf("hello world%-hhs% 14s%#19.31s%++-#s");
	// ft_printf("%hs");
	// ft_printf("%lls");
	// ft_printf("%ls");
	// ft_printf("%js");
	// ft_printf("%zs");
	// ft_printf("%lld", z);
	// ft_printf("%s", "hello");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return (0);
}
