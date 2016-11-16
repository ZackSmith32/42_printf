/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:28:52 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/15 22:21:23 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct	a_list
{
	int				minus;
	int				plus;
	int				hash;
	int				space;
	int				zero;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				j;
	int				z;
	int				width;
	int				w_star;
	int				prec;
	int				p_star;
	int				chr_cnt;
	void			(*f)(struct a_list *obj, va_list);
	char			*str;
	struct a_list	*next;
}					conv_obj;

typedef struct		z_list
{
	char			f_nm;
	void			(*f)(struct a_list *obj, va_list);
}					f_list;

extern f_list		g_func_arr[15];
extern char 		*g_flag_norm;
extern char 		*g_flag_length;

/*
**	list_funx
*/
void		ft_lstadd_end(conv_obj *temp, conv_obj *new);
void		ft_putlist(conv_obj *t);
conv_obj	*new_conv_obj(void);

/*
**	pop_funx
*/
void		pop_str(conv_obj *obj, char **str);
void		pop_flags(conv_obj *obj, char **sentinel);
void		pop_width(conv_obj *obj, char **sentinel);
void		pop_precision(conv_obj *obj, char **sentinel);
void		pop_length(conv_obj *obj, char **sentinel);

/*
** pop_funx2
*/
void	pop_con(conv_obj *obj, char **sentinel);

/*
**	help_funx
*/
int			temp_not_null(conv_obj *temp);
int			ft_strcmp_c(char *str, char c);
void		test_print(conv_obj *obj);

/*
** con_funx
*/
void		s_func(conv_obj *obj, va_list args);
// void		S_func(conv_obj *obj, va_list args);
// void		p_func(conv_obj *obj, va_list args);
// void		d_func(conv_obj *obj, va_list args);
// void		D_func(conv_obj *obj, va_list args);
// void		i_func(conv_obj *obj, va_list args);
// void		o_func(conv_obj *obj, va_list args);
// void		O_func(conv_obj *obj, va_list args);
// void		u_func(conv_obj *obj, va_list args);
// void		U_func(conv_obj *obj, va_list args);
// void		x_func(conv_obj *obj, va_list args);
// void		X_func(conv_obj *obj, va_list args);
// void		c_func(conv_obj *obj, va_list args);
// void		C_func(conv_obj *obj, va_list args);



#endif