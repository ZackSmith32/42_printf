/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:18 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/11 19:48:12 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_func(conv_obj *obj, va_list args)
{
	// printf("obj->str = %s\n", obj->str);
	o_func(obj, args);
}

void	X_func(conv_obj *obj, va_list args)
{
	int		i;

	o_func(obj, args);
	i = 0;
	while ((obj->str)[i])
	{
		obj->str[i] = ft_toupper((obj->str)[i]);
		i++;
	}
	return ;
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
