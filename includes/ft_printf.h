/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:28:52 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 13:22:01 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>	// malloc
#include <unistd.h>	// write
#include <stdarg.h> // va_list
#include <stdint.h> // intmax_t
#include <wchar.h>	// wint_t
#include "libft/libft.h"

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
	int				extra;
	void			(*f)(struct a_list *obj, va_list args);
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
**			ft_printf
*/
int			pop_obj(conv_obj *obj, char **sentinel);
int			mission_control(char **sentinel, va_list args);
int			ft_printf(char *sentinel, ...);

/*
**			funx__list
*/
void		ft_lstadd_end(conv_obj *temp, conv_obj *new);
int			ft_putobj(conv_obj *t);
conv_obj	*new_conv_obj(void);

/*
**			funx__pop
*/
void		pop_str(conv_obj *obj, char **str);
void		pop_flags(conv_obj *obj, char **sentinel);
void		pop_width(conv_obj *obj, char **sentinel);
void		pop_precision(conv_obj *obj, char **sentinel);
void		pop_length(conv_obj *obj, char **sentinel);

/*
** 			funx__pop2
*/
void		pop_con(conv_obj *obj, char **sentinel);
void		non_func(conv_obj *obj, va_list args);
void		pop_parse(conv_obj *obj);
int			ft_strc(char *str, char c);

/*
**			funx__help
*/
char		*ft_itoa3(long long nbr);
char		*ft_itoa_base(unsigned long long n, int base);
int			utf_len(wchar_t *wide);

/*
**			funx__flag
*/
void		plus_func(conv_obj *obj);
void		space_flag(conv_obj *obj);	
void		star_args(conv_obj *obj, va_list args);

/*
**			funx__wide
*/
char		*s_wide(wchar_t wide);

/*
**			funx_d
*/
void		D_func(conv_obj *obj, va_list args);
void		d_func(conv_obj *obj, va_list args);
void		d_width(conv_obj *obj);
void		d_precision(conv_obj *obj);
void		d_width_zero(conv_obj *obj);

/*
**			funx_s
*/
void		s_func(conv_obj *obj, va_list args);
void		S_func(conv_obj *obj, va_list args);
void		c_func(conv_obj *obj, va_list args);
void		C_func(conv_obj *obj, va_list args);

/*
**			funx_o
*/
void		o_func(conv_obj *obj, va_list args);
void		O_func(conv_obj *obj, va_list args);

/*
**			funx_u
*/
void		u_func(conv_obj *obj, va_list args);
void		U_func(conv_obj *obj, va_list args);

/*
**			funx_x
*/
void		x_func(conv_obj *obj, va_list args);
void		X_func(conv_obj *obj, va_list args);
void		x_hash(conv_obj *obj);
void		x_hash_alt(conv_obj *obj);

/*
**			funx_pi
*/
void		p_func(conv_obj *obj, va_list args);
void		i_func(conv_obj *obj, va_list args);
void		non_func(conv_obj *obj, va_list args);

#endif