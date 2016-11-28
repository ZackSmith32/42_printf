/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_spec_xXcC.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/27 13:31:28 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// #include "../includes/func_list.h"

void	x_func(conv_obj *obj, va_list args)
{
	if (DEBUG_o) printf("in x_func\n");

	o_func(obj, args);
}

void	X_func(conv_obj *obj, va_list args)
{
	if (DEBUG_o) printf("in X_func\n");
	int		i;

	o_func(obj, args);
	if (DEBUG_o) printf("X_func: after o_func: str: %s\n", obj->str);
	i = 0;
	while ((obj->str)[i])
	{
		obj->str[i] = ft_toupper((obj->str)[i]);
		i++;
	}
	return ;
}

void	c_func(conv_obj *obj, va_list args)
{
	return ;
}

void	C_func(conv_obj *obj, va_list args)
{
	return ;
}
