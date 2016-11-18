/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_spec_sSpdD.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/18 10:56:35 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// #include "../includes/func_list.h"

void	s_func(conv_obj *obj)
{
	return ;
}

void	S_func(conv_obj *obj)
{
	return ;
}

void	p_func(conv_obj *obj)
{
	return ;
}

void	d_func(conv_obj *obj)
{
	obj->str = ft_itoa2(obj->data);
	
	return ;
}

void	D_func(conv_obj *obj)
{
	return ;
}
