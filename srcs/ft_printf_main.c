/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:09:46 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/14 01:20:59 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <limits.h>
#include <locale.h>
#include <stdint.h> 

int		main(void)
{
	setlocale(LC_ALL, "");
	
	ft_printf("hex: %x, dec: %d, oct: %o, bin: %hhb", 42, 42, 42, 42);

	return (0);
}

