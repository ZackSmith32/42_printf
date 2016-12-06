/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:55:55 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/04 22:52:09 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *g_flag_norm = "-+# 0";
char *g_flag_length = "hljz";

f_list g_func_arr[] = {
	{'s', &s_func},
	{'S', &S_func},
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

int		DEBUG = 0;
int		DEBUG_D = 0;
int		DEBUG_POP = 0;
int		DEBUG_o = 0;
int		DEBUG_s = 0;
int		DEBUG_c = 0;
int		DEBUG_LIST = 0;
