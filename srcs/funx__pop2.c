/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__pop2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:00:51 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/11 19:36:49 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pop_con(conv_obj *obj, char **sentinel)
{
	// printf("sentinel = %s\n", *sentinel);
	int		i;

	i = 0;
	while (i < 15)
	{
		if (g_func_arr[i].f_nm == **sentinel)
		{
			obj->con_typ = **sentinel;
			obj->f = g_func_arr[i].f;
			(*sentinel)++;
			break ;
		}
		i++;
	}
	if (i == 15)
	{
		obj->con_typ = **sentinel;
		obj->f = g_func_arr[14].f;
		(*sentinel)++;
	}
}

void	pop_parse(conv_obj *obj, char **sentinel)
{
	if (obj->minus == 1)
		obj->zero = 0;
	if (obj->plus == 1)
		obj->space = 0;
	(*sentinel)--;
	if (obj->prec != -1 && !(obj->con_typ == 'c' 
		|| obj->con_typ == 'C' || obj->con_typ == 's' || obj->con_typ == 'S'
		|| obj->con_typ == '%' || obj->con_typ == **sentinel))
	{
		printf("in if\n");
		obj->zero = 0;
	}
	(*sentinel)++;
}
