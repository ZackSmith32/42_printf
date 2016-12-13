/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:26:23 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 11:22:05 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int		pop_obj(conv_obj *obj, char **sentinel)
{
	if (**sentinel == '%')
	{
		(*sentinel)++;
		pop_flags(obj, sentinel);
		pop_width(obj, sentinel);
		// printf("1sent = %s\n", *sentinel);
		pop_precision(obj, sentinel);
		// printf("2sent = %s\n", *sentinel);
		pop_length(obj, sentinel);
		// printf("3sent = %s\n", *sentinel);
		pop_con(obj, sentinel);
		pop_parse(obj, sentinel);
	}
	else
		pop_str(obj, sentinel);
	return (1);
}

int		mission_control(char **sentinel, va_list args)
{
	conv_obj	*item;
	conv_obj	*temp;
	int			i;

	temp = new_conv_obj();
	item = temp;
	i = 0;
	if (**sentinel == 0)
	{
		free(temp->str);
		item->str = ft_strdup("");
	}
	while (sentinel[0][0] != '\0')
	{
		if (i)
			temp  = new_conv_obj();
		// printf("temp -> %p\n", temp->str);
		pop_obj(temp, sentinel);
		if (temp->f)
		{
			// printf("con typ = %c\n", temp->con_typ);
			(temp->f)(temp, args);
		}
		else if (ft_strchr(temp->str, '*') != NULL)
			temp->str = ft_strdup("");
		ft_lstadd_end(item, temp);
		i++;
	}
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
