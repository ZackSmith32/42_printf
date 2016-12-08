/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_spec_ioOuU.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 10:36:47 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// #include "../includes/func_list.h"

void	i_func(conv_obj *obj, va_list args)
{
	d_func(obj, args);
	return ;
}

void	o_func(conv_obj *obj, va_list args)
{
	if (DEBUG_o) printf("o_func: in\n");
	int		n;
	unsigned long	check;

	star_args(obj, args);
	if (obj->con_typ == 'o')
		n = 8;
	else
		n = 16;
	if (!ft_strcmp(obj->len_f, "l") || !ft_strcmp(obj->len_f, "ll"))
		obj->str = ft_itoa_base(va_arg(args, unsigned long long), n);
	if (!ft_strcmp(obj->len_f, "j") || !ft_strcmp(obj->len_f, "z"))
	{
		check = va_arg(args, unsigned long);
		obj->str = ft_itoa_base(check, n);
	}
	if (!ft_strcmp(obj->len_f, "hh") || !ft_strcmp(obj->len_f, "h")
		|| !ft_strlen(obj->len_f))
		obj->str = ft_itoa_base(va_arg(args, unsigned int), n);
	if (ft_strlen(obj->str) == 0)
		return ;
	d_precision(obj);
	// printf("obj->str = %s\n", obj->str);
	o_hash(obj);
	x_hash(obj);
	d_width(obj);
	x_hash_alt(obj);
}

void	o_hash(conv_obj *obj)
{
	// printf("o_hash\n");
	char	*new;

	if (!obj->hash || !(obj->con_typ == 'o'))
		return ;
	// if ((obj->str)[0] == 0)
	// 	return ;
	new = (char *)ft_memalloc(ft_strlen(obj->str) + 2);
	new[0] = '0';
	ft_strcpy(new + 1, obj->str);
	// printf("new = %s\n", obj->str);
	free(obj->str);
	obj->str = new;
}

void	x_hash(conv_obj *obj)
{
	char	*new;

	if (!obj->str[0] || !ft_strcmp(obj->str, "0"))
		return ;
	if (!obj->hash || !((obj->con_typ == 'x') || (obj->con_typ == 'X')) 
		|| obj->zero == 1 )
		return ;
	new = (char *)ft_memalloc(ft_strlen(obj->str) + 3);
	new[0] = '0';
	new[1] = obj->con_typ;	
	ft_strcpy(new + 2, obj->str);
	free(obj->str);
	obj->str = new;
}

void	x_hash_alt(conv_obj *obj)
{
	int		i;
	char	*new;

	if (!obj->str[0] || !ft_strcmp(obj->str, "0"))
		return ;
	if (!obj->hash || !((obj->con_typ == 'x') || (obj->con_typ == 'X')) 
		|| obj->zero == 0 || obj->minus == 1)
		return ;
	i = 0;
	while (obj->str[i] == '0')
		i++;
	if (i < 2)
	{
		new = (char *)ft_memalloc(ft_strlen(obj->str) + (2 - i) + 1);
		new[0] = '0';
		new[1] = obj->con_typ;
		ft_strcpy(new + 2, obj->str);
		free(obj->str);
		obj->str = new;
	}	
	else 
	{
		obj->str[0] = '0';
		obj->str[1] = obj->con_typ;
	}
}

void	O_func(conv_obj *obj, va_list args)
{
	o_func(obj, args);
	return ;
}

void	u_func(conv_obj *obj, va_list args)
{
	star_args(obj, args);
	if (obj->w_star)
		obj->width = va_arg(args, int);
	if (obj->p_star)
		obj->prec = va_arg(args, int);
	if (!ft_strcmp(obj->len_f, "hh"))
		obj->str = ft_itoa3((unsigned char)va_arg(args, unsigned int));
	if (!ft_strcmp(obj->len_f, "h"))
		obj->str = ft_itoa3((unsigned short)va_arg(args, unsigned int));
	if (!ft_strlen(obj->len_f))
	{
		obj->str = ft_itoa3((unsigned int)va_arg(args, unsigned int));
	}
	if (!ft_strcmp(obj->len_f, "l")
			|| !ft_strcmp(obj->len_f, "ll"))
		obj->str = ft_itoa3((unsigned long)va_arg(args, unsigned long long));
	if (!ft_strcmp(obj->len_f, "j")
		|| !ft_strcmp(obj->len_f, "z"))
		obj->str = ft_itoa3(va_arg(args, unsigned long long));
	d_precision(obj);
	plus_func(obj);
	space_flag(obj);
	if (ft_strlen(obj->str) == 0)
		return ;
	d_width(obj);
	return ;
}

void	U_func(conv_obj *obj, va_list args)
{
	d_func(obj, args);
	return ;
}






















