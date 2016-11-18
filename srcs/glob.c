/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:55:55 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/17 08:21:48 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *g_flag_norm = "-+# 0";
char *g_flag_length = "h,hh,l,ll,j,z,";

f_list g_func_arr[] = {
	{'s', &S_func},
	{'p', &p_func},
	{'d', &d_func},
	{'D', &D_func},
	{'i', &i_func},
	{'o', &o_func},
	{'O', &O_func},
	{'u', &u_func},
	{'U', &U_func},
	{'x', &x_func},
	{'X', &X_func},
	{'c', &c_func},
	{'C', &C_func}
};



