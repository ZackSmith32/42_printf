/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:59:38 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/20 17:19:43 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	plus_func(conv_obj *obj)
{
	if (DEBUG_D) printf("plus_func: in\n");
	char	*ind;
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

	if (!obj->space)
		return ;
	if (obj->zero && (obj->width > obj->prec))
	{
		(obj->str)[0] = 32;
		return ;
	}
	if (obj->prec >= obj->width)
	{	
		new_str = ft_memalloc(ft_strlen(obj->str) + 2);
		new_str[0] = ' ';
		ft_strcpy(new_str + 1, obj->str);
		free(obj->str);
		obj->str = new_str;
	}
}

