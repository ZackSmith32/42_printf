/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:26:23 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/07 16:00:00 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <locale.h>
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
int		pop_obj(conv_obj *obj, char **sentinel)
{
	if (DEBUG) printf("pop_obj: in : sentinel = %s\n", *sentinel);

	if (**sentinel == '%')
	{
		pop_flags(obj, sentinel);
		pop_width(obj, sentinel);
		pop_precision(obj, sentinel);
		pop_length(obj, sentinel);
		pop_con(obj, sentinel);
		pop_parse(obj);
	} else {
		pop_str(obj, sentinel);
	}
	// printf("pop_obj: str: %s\n", obj->str);
	// printf("pop_obj: plus: %d\n", obj->plus);
	// (*sentinel)++;
	// printf("pop_obj: con_typ = %c\n", obj->con_typ);
	// increment_sent(obj);
	// printf("pop_obj: n: %d\n", obj->n);
	if (DEBUG) printf("pop_obj: out: sentinel = %s\n", *sentinel);
	return (1);
}

int		mission_control(char **sentinel, va_list args)
{
	if (DEBUG) printf("mc: in:\n");
	conv_obj	*item;
	conv_obj	*temp;
	int			i;

	temp = new_conv_obj();
	item = temp;
	i = 0;
	while (sentinel[0][0] != '\0')
	{
		if (DEBUG) printf(">>>>>>>>>>>>>start\n");
		// if (1) printf("mc: sentinel: %s\n", *sentinel);
		if (i)
			temp  = new_conv_obj();
		pop_obj(temp, sentinel);
		if (temp->f)
			(temp->f)(temp, args);
		// test_print(temp);
		ft_lstadd_end(item, temp);
		i++;
		if (DEBUG) printf(">>>>>>>>>>>>>end\n\n");
	}
	// test_print(item);
	// printf("mc: temp->str: %s\n", temp->str);
	return (ft_putobj(item));
}

int		ft_printf(char *sentinel, ...)
{
	va_list args;

	va_start(args, sentinel);
	return (mission_control(&sentinel, args));
	va_end(args);
	return (0);
}

















	/* wide char strings */
	/*
	setlocale(LC_ALL, "");

	wint_t		y;
	wchar_t			*z;
	wint_t		c;

	z = L"abcd";
	c = L'b';

	ft_printf("%C", 'c');
	ft_printf("%ls", z);
	printf("%ls", z);

	y = 0x0011;
	ft_printf("%s", "R€¢Ż😁");	
	ft_printf("%s", "¢");
	ft_printf("%s", "Ż");
	ft_printf("%s", "😁");
	printf("%s\n", "😁");

	¢ : 2 bytes
	€ : 3 bytes
	😁 : 4 bytes
	Ż
	*/

	/* precision and width testing */

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

