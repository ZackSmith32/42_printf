/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_funx2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:00:51 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/20 14:30:37 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pop_con(conv_obj *obj, char **sentinel)
{
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
}

void	pop_len_args(conv_obj *obj, va_list args)
{
	if (obj->con_typ == 'd')
		pop_d_data(obj, args);
}

void	pop_d_data(conv_obj *obj, va_list args)
{
	if (obj->w_star)
		obj->data_w_star = va_arg(args, int);
	if (obj->p_star)
		obj->data_p_star = va_arg(args, int);
	if (obj->len_f == 'i')
		obj->l = va_args(args, signed char);
	if (obj->len_f == 'h')
		obj->m = va_args(args, short);
	if (obj->len_f == 'k')
		obj->n = va_args(args, int);
	if (obj->len_f == 'l')
		obj->o = va_args(args, long);
	if (obj->len_f == 'j')
		obj->p = va_args(args, long long);
	if (obj->len_f == 'z')
		obj->p = va_args(args, intmax_t);
}


// void	pop_malloc_data(conv_obj *obj)
// {
// 	if (obj->length = hh)
// 		obj->data = (void *)malloc(sizeof(short));
// 	if (obj->length = ll)
// 		obj->data = (void *)malloc(sizeof(long long));
// }