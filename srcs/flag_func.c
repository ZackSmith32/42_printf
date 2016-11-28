/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:59:38 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/27 13:20:14 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	plus_func(conv_obj *obj)
{
	if (DEBUG_D) printf("plus_func: in\n");
	char	*new_str;

	if (obj->plus == 0)
		return ;
	if (ft_strchr(obj->str, '-'))
		return ;
	new_str = ft_memalloc(ft_strlen(obj->str) + 2);
	new_str[0] = '+';
	ft_strcat(new_str, obj->str);
	free(obj->str);
	obj->str = new_str;
	if (DEBUG_D) printf("plus_func: out: obj->str = %s\n", obj->str);
}

void	space_flag(conv_obj *obj)
{
	char	*new_str;

	if (obj->space == 0)
		return ;
	if (ft_strchr(obj->str, '-'))
		return ;
	new_str = ft_memalloc(ft_strlen(obj->str) + 2);
	new_str[0] = ' ';
	ft_strcat(new_str, obj->str);
	free(obj->str);
	obj->str = new_str;
}

void	star_args(conv_obj *obj)
{
	if (obj->p_star)
		obj->prec = va_arg(args, int);
	if (obj->w_star)
		obj->width = va_arg(args, int);
}