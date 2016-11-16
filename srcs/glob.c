/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:55:55 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/15 22:15:42 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *g_flag_norm = "-+# 0";
char *g_flag_length = "h,hh,l,ll,j,z,";

f_list g_func_arr[] = {
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func},
	{'s', &s_func}
};

