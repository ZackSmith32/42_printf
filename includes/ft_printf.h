/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:28:52 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/20 14:32:22 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h> // intmax_t
#include "libft/libft.h"

typedef struct	a_list
{
	int				minus;
	int				plus;
	int				hash;
	int				space;
	int				zero;
	char			len_f;
	int				width;
	int				w_star;
	int				prec;
	int				p_star;
	signed char		l;
	short			m;
	int				n;
	long			o;
	long long		p;
	char			con_typ;
	void			(*f)(struct a_list *obj);
	int				chr_cnt;
	int				data_p_star;
	int				data_w_star;
	char			*str;
	struct a_list	*next;
}					conv_obj;

typedef struct		z_list
{
	char			f_nm;
	void			(*f)(struct a_list *obj);
}					f_list;

extern f_list		g_func_arr[15];
extern char 		*g_flag_norm;
extern char 		*g_flag_length;

/*
**			list_funx
*/
void		ft_lstadd_end(conv_obj *temp, conv_obj *new);
void		ft_putlist(conv_obj *t);
conv_obj	*new_conv_obj(void);

/*
**			pop_funx
*/
void		pop_str(conv_obj *obj, char **str);
void		pop_flags(conv_obj *obj, char **sentinel);
void		pop_width(conv_obj *obj, char **sentinel);
void		pop_precision(conv_obj *obj, char **sentinel);
void		pop_length(conv_obj *obj, char **sentinel);

/*
** 			pop_funx2
*/
void		pop_con(conv_obj *obj, char **sentinel);
void		pop_d_data(conv_obj *obj, va_list args);
void		pop_len_args(conv_obj *obj, va_list args);



/*
**			help_funx
*/
int			temp_not_null(conv_obj *temp);
int			ft_strcmp_c(char *str, char c);
void		test_print(conv_obj *obj);
char			*ft_itoa2(long long nbr);
int			ft_numlen2(long num);

/*
** 			con_funx
*/
void		s_func(conv_obj *obj);
void		S_func(conv_obj *obj);
void		p_func(conv_obj *obj);
void		d_func(conv_obj *obj);
void		D_func(conv_obj *obj);
void		i_func(conv_obj *obj);
void		o_func(conv_obj *obj);
void		O_func(conv_obj *obj);
void		u_func(conv_obj *obj);
void		U_func(conv_obj *obj);
void		x_func(conv_obj *obj);
void		X_func(conv_obj *obj);
void		c_func(conv_obj *obj);
void		C_func(conv_obj *obj);
void		d_func2(conv_obj *obj);

/*
** 			type_conv_funx
*/
void		type_conv_hq(conv_obj *obj, va_list args);
void		hh_type(conv_obj *obj, va_list args);
void		h_type(conv_obj *obj, va_list args);
void		ll_type(conv_obj *obj, va_list args);
void		l_type(conv_obj *obj, va_list args);

/*
**			type_conv_funx2
*/
void		j_type(conv_obj *obj, va_list args);
void		z_type(conv_obj *obj, va_list args);
void		none_type(conv_obj *obj, va_list args);

/*
**			flag_funx
*/

void		plus_func(conv_obj *obj);
























#endif