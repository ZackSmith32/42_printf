/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:09:46 by zsmith            #+#    #+#             */
/*   Updated: 2017/01/02 16:51:14 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>
#include <locale.h>
#include <stdint.h> 

int		main(void)
{
	setlocale(LC_ALL, "");
	
	ft_printf("%@cyan@4.15d", -424242);
	printf("\n");
	printf("%4.15d", -424242);

	return (0);
}

