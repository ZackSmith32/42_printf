/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_spec_sSpdD.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/19 21:32:40 by zsmith           ###   ########.fr       */
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
	/*
	**	resolve to make an entry in the struct for each data
	**	type, then maybe be able to use 1 itoa to convert
	**	all the diff data types to strings cept unsigned ll
	*/
	signed char	a;
	short 		b;
	int			c;
	long		d;
	long long	e;
	

	a = 2;
	b = -2;
	c = -2;
	d = -2;
	e = -2;

	printf("%s\n", ft_itoa2(a));
	printf("%s\n", ft_itoa2(b));
	printf("%s\n", ft_itoa2(c));
	printf("%s\n", ft_itoa2(d));
	printf("%s\n", ft_itoa2(e));

	// printf("obj->data = %lld\n", (long long)obj->data);
	// printf("obj->data = %d\n", (int)obj->data);
	// if (obj->l == 1 || obj->ll == 1)
	// {
	// 	obj_str = ft_itoa_long((long)obj->data);
	// } else {
	// 	obj->str = ft_itoa_int((int)obj->data);
	// }
	obj->str = ft_itoa2((long long)obj->data);
	// obj->str = ft_itoa2(obj->data);
	// obj->str = ft_itoa2(a);


	// plus_func(obj);	
	return ;
}

void	D_func(conv_obj *obj)
{
	return ;
}

