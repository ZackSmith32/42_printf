/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:15:12 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/15 22:22:11 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		temp_not_null(conv_obj *temp)
{
	if ( 	
			temp->minus == 0 &&
			temp->plus == 0 &&
			temp->hash == 0 &&
			temp->space == 0 &&
			temp->zero == 0 &&
			temp->hh == 0 &&
			temp->h == 0 &&
			temp->l == 0 &&
			temp->ll == 0 &&
			temp->j == 0 &&
			temp->z == 0 &&
			temp->width == 0 &&
			temp->w_star == 0 &&
			temp->prec == 0 &&
			temp->p_star == 0 &&
			temp->str == 0
		)
		return (0);
	return (1);
}

int		ft_strcmp_c(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	test_print(conv_obj *obj)
{
	printf("minus  : %d\n", obj->minus);
	printf("plus   : %d\n", obj->plus);
	printf("hash   : %d\n", obj->hash);
	printf("space  : %d\n", obj->space);
	printf("zero   : %d\n", obj->zero);
	printf("hh     : %d\n", obj->hh);
	printf("h      : %d\n", obj->h);
	printf("l      : %d\n", obj->l);
	printf("ll     : %d\n", obj->ll);
	printf("j      : %d\n", obj->j);
	printf("z      : %d\n", obj->z);
	printf("width  : %d\n", obj->width);
	printf("w_star : %d\n", obj->w_star);
	printf("prec   : %d\n", obj->prec);
	printf("p_star : %d\n", obj->p_star);
	printf("chr_cnt: %d\n", obj->chr_cnt);
	printf("str    : %s\n", obj->str);
	if (obj->f)
		printf("func   : yes\n");
}