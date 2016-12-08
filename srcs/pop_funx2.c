/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_funx2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:00:51 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 09:04:22 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pop_con(conv_obj *obj, char **sentinel)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (g_func_arr[i].f_nm == **sentinel)
		{
			if (DEBUG) printf("pop_con: %c\n", **sentinel);
			obj->con_typ = **sentinel;
			obj->f = g_func_arr[i].f;
			(*sentinel)++;
			break ;
		}
		i++;
	}
}

void	pop_parse(conv_obj *obj)
{
	if (obj->minus == 1)
		obj->zero = 0;
	if (obj->plus == 1)
		obj->space = 0;
	if (obj->prec != -1)
		obj->zero = 0;
}
