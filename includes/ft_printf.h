/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:28:52 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/04 22:42:04 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h> // va_list
#include <stdint.h> // intmax_t
#include <wchar.h>	// wint_t
#include "libft/libft.h"

extern int DEBUG;
extern int DEBUG_D;
extern int DEBUG_POP;
extern int DEBUG_o;
extern int DEBUG_s;
extern int DEBUG_c;

typedef struct	a_list
{
	int				minus;
	int				plus;
	int				hash;
	int				space;
	int				zero;
	char			*len_f;
	int				width;
	int				w_star;
	int				prec;
	int				p_star;
	char			con_typ;
	int				data_p_star;
	int				data_w_star;
	void			(*f)(struct a_list *obj, va_list args);
	int				chr_cnt;
	char			*str;
	struct a_list	*next;
}					conv_obj;

typedef struct		z_list
{
	char			f_nm;
	void			(*f)(struct a_list *obj, va_list args);
}					f_list;

extern f_list		g_func_arr[15];
extern char 		*g_flag_norm;
extern char 		*g_flag_length;

/*
**			list_funx
*/
void		ft_lstadd_end(conv_obj *temp, conv_obj *new);
void		ft_putobj(conv_obj *t);
conv_obj	*new_conv_obj(void);
void		test_print(conv_obj *obj);

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

/*
**			help_funx
*/
int			temp_not_null(conv_obj *temp);
int			ft_strc(char *str, char c);
char		*ft_itoa3(long long nbr);
char		*ft_itoa_base(unsigned long long n, int base);
int			ft_numlen_base(long long n, int base);

/*
**			help_funx2
*/
int			utf_len(wchar_t *wide);


/*
** 			con_funx
*/
void		i_func(conv_obj *obj, va_list args);
void		O_func(conv_obj *obj, va_list args);
void		u_func(conv_obj *obj, va_list args);
void		U_func(conv_obj *obj, va_list args);
void		x_func(conv_obj *obj, va_list args);
void		X_func(conv_obj *obj, va_list args);

/*
**			d_funx
*/
void		D_func(conv_obj *obj, va_list args);
void		d_func(conv_obj *obj, va_list args);
void		d_width(conv_obj *obj);
void		d_precision(conv_obj *obj);

/*
**			o_funx
*/
void		o_func(conv_obj *obj, va_list args);
void		o_hash(conv_obj *obj);
void		x_hash(conv_obj *obj);

/*
**			s_funx
*/
void		s_func(conv_obj *obj, va_list args);
void		S_func(conv_obj *obj, va_list args);
void		c_func(conv_obj *obj, va_list args);
void		C_func(conv_obj *obj, va_list args);

/*
**			xp_funx
*/
void		p_func(conv_obj *obj, va_list args);


/*
**			flag_funx
*/
void		plus_func(conv_obj *obj);
void		space_flag(conv_obj *obj);	
void		star_args(conv_obj *obj, va_list args);


























#endif