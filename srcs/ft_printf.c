/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:26:23 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/12 19:57:40 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*parse(char **sentinel, va_list args)
{
	
	conv_calc(sentinel, args)
	(*sentinel)++;
	return (" goodbye");
}

char	*mission_control(char **sentinel, va_list args, char *print_str)
{
	printf("in: mission control\n");
	char	*temp;

	temp = ft_memalloc(2);
	temp[0] = sentinel[0][0];
	if (**sentinel == '\0')
		return (print_str);
	else if (**sentinel != '%')
	{
		print_str = ft_strjoin(print_str, temp);
		(*sentinel)++;
	}
	else
		print_str = ft_strjoin(print_str, parse(sentinel, args));
	return (mission_control(sentinel, args, print_str));
}

int		ft_printf(char *sentinel, ...)
{
	va_list args;
	char	*print_str;

	print_str = ft_memalloc(1);
	va_start(args, sentinel);
	ft_putstr(mission_control(&sentinel, args, print_str));
	va_end(args);

	return (0);
}

int		main(void)
{
	ft_printf("hello%");
	return (0);
}



/*
	while (1)
	{
		if ((i = va_arg(args, int)))
			printf("%d\n", i);
		else
			break ;
	}
*/