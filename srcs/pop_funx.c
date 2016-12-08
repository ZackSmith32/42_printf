/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_funx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:12:29 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 10:19:59 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pop_str(conv_obj *obj, char **str)
{
	if (DEBUG_POP) printf("pop_str: sentinel: %s\n", *str);

	int		i;
	int		j;
	char	*p_str;

	i = 0;
	while (str[0][i] != '%' && str[0][i] != '\0')
		i++;
	p_str = (char *)malloc(i + 1);
	j = 0;
	while (j < i)
	{
		p_str[j] = **str;
		(*str)++;
		j++;
	}
	p_str[j] = '\0';
	if (DEBUG_POP) printf("pop_str: p_str: %s\n", p_str);
	obj->str = p_str;
	obj->con_typ = 't';
}

void	pop_flags(conv_obj *obj, char **sentinel)
{
	if (**sentinel == '%')
		(*sentinel)++;
	else
		return ;
	while (ft_strc(g_flag_norm, **sentinel) != 0)
	{
		if (**sentinel == '-')
			obj->minus = 1;
		if (**sentinel == '+')
			obj->plus = 1;
		if (**sentinel == '#')
			obj->hash = 1;
		if (**sentinel == ' ')
			obj->space = 1;
		if (**sentinel == '0')
			obj->zero = 1;
		(*sentinel)++;
	}
	obj->str = "*";
	// printf("pop_flags obj->plus = %d\n", obj->plus);
}

void	pop_width(conv_obj *obj, char **sentinel)
{
	int		i;
	char	*holder;

	i = 0;
	while (ft_isdigit(sentinel[0][i]))
		i++;
	holder = ft_memalloc(i + 1);
	i = 0;
	while (ft_isdigit(**sentinel))
	{
		holder[i] = **sentinel;
		(*sentinel)++;
		i++;
	}
	holder[i] = '\0';
	i = ft_atoi(holder);
	obj->width = i;
	// printf("pop_width: obj->width = %d\n", i);
}

void	pop_precision(conv_obj *obj, char **sentinel)
{
	int		i;
	char	*holder;

	if (**sentinel == '.')
		(*sentinel)++;
	else
		return ;
	i = 0;
	while (ft_isdigit(sentinel[0][i]))
		i++;
	holder = (char *)ft_memalloc(i + 1);
	i = 0;
	while (ft_isdigit(**sentinel))
	{
		holder[i] = **sentinel;
		(*sentinel)++;
		i++;
	}
	holder[i] = '\0';
	i = ft_atoi(holder);
	obj->prec = i;
}

void	pop_length(conv_obj *obj, char **sentinel)
{
	if (DEBUG_POP) printf("pop_length:  in:\n");
	if (**sentinel == 'h' && (*sentinel)[1] == 'h')
	{
		obj->len_f = "hh";
		(*sentinel)++;
	}
	else if (**sentinel == 'h')
		obj->len_f = "h";
	if (**sentinel == 'l' && (*sentinel)[1] == 'l')
	{
		obj->len_f = "ll";
		(*sentinel)++;
	}
	else if (**sentinel == 'l')
		obj->len_f = "l";
	if (**sentinel == 'j')
		obj->len_f = "j";
	if (**sentinel == 'z')
		obj->len_f = "z";
	if (ft_strc(g_flag_length, **sentinel))
		(*sentinel)++;
	if (DEBUG_POP) printf("pop_length: out: obj->len_f = %s\n", obj->len_f);
	obj->str = ft_strdup("*");
}


















