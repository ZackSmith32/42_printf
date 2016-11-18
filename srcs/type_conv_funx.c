/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conv_funx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:10:33 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/17 10:49:05 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	type_conv_hq(conv_obj *obj, va_list args)
{
	if (obj->hh)
		hh_type(obj, args);
	else if (obj->h)
		h_type(obj, args);
	else if (obj->ll)
		ll_type(obj, args);
	else if (obj->l)
		l_type(obj, args);
	else if (obj->j)
		j_type(obj, args);
	else if (obj->z)
		z_type(obj, args);
	else
		none_type(obj, args);
}

void	hh_type(conv_obj *obj, va_list args)
{
	obj->data = va_arg(args, void*);
	// printf("hh_type: in\n");
	// if (obj->con_typ == 'd' || obj->con_typ == 'i')
	// {
	// 	obj->data = (char *)va_arg(args, void*);
	// 	printf("hh_type: di: %%c: %c\n", (obj->data)[0]);
	// }
	// if (obj->con_typ == 'o' || obj->con_typ == 'x' || obj->con_typ == 'X'
	// 	 || obj->con_typ == 'u')
	// {
	// 	obj->data = (unsigned char*)va_arg(args, void*);
	// 	printf("hh_type: oxXu: %%c: %c\n", obj->data);
	// }
}
void	h_type(conv_obj *obj, va_list args)
{
	printf("hh_type: in\n");
	if (obj->con_typ == 'd' || obj->con_typ == 'i')
	{
		obj->data = (short *)va_arg(args, void*);
		// printf("h_type: di: %%d: %d\n", obj->data);
	}
	if (obj->con_typ == 'o' || obj->con_typ == 'x' || obj->con_typ == 'X'
		 || obj->con_typ == 'u')
	{
		obj->data = (unsigned short *)va_arg(args, void*);
		// printf("h_type: oxXu: %%d: %d\n", obj->data);
	}
}
void	ll_type(conv_obj *obj, va_list args)
{
	return ;
}
void	l_type(conv_obj *obj, va_list args)
{
	return ;
}







	// int		x;

	// x = (int)va_arg(args, void*);
	// printf("test of va_args: %d\n", x);

















