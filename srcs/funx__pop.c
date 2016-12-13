/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:12:29 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/12 22:27:39 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pop_str(conv_obj *obj, char **str)
{
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
	free(obj->str);
	obj->str = p_str;
	obj->con_typ = 't';
}

void	pop_flags(conv_obj *obj, char **sentinel)
{
	// printf("pop_flags: sentinel = %s\n", *sentinel);
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
	// printf("pop_flags: out: minus = %c\n", obj->minus);
}

void	pop_width(conv_obj *obj, char **sentinel)
{
	int		i;
	char	*holder;

	i = 0;
	if (**sentinel == '*')
	{
		obj->w_star = 1;
		(*sentinel)++;
		return ;
	}
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
	free(holder);
	obj->width = i;
}

int		star_check(conv_obj *obj, char **sentinel)
{	
	if (**sentinel == '*')
	{
		obj->p_star = 1;
		(*sentinel)++;
		return (1);
	}
	return (0);
}

void	pop_precision(conv_obj *obj, char **sentinel)
{
	int		i;
	char	*holder;

	if (**sentinel == '.')
		(*sentinel)++;
	else
		return ;
	if (star_check(obj, sentinel))
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
	free(holder);
	obj->prec = i;
}

void	pop_length(conv_obj *obj, char **sentinel)
{
	if (**sentinel == 'h' && (*sentinel)[1] == 'h')
	{
		ft_strcpy(obj->len_f, "hh");
		(*sentinel)++;
	}
	else if (**sentinel == 'h')
		ft_strcpy(obj->len_f, "h");
	if (**sentinel == 'l' && (*sentinel)[1] == 'l')
	{
		ft_strcpy(obj->len_f, "ll");
		(*sentinel)++;
	}
	else if (**sentinel == 'l')
		ft_strcpy(obj->len_f, "l");
	if (**sentinel == 'j')
		ft_strcpy(obj->len_f, "j");
	if (**sentinel == 'z')
		ft_strcpy(obj->len_f, "z");
	if (ft_strc(g_flag_length, **sentinel))
		(*sentinel)++;
}


















