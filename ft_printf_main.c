/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:09:46 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/17 20:15:05 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <limits.h>
#include <locale.h>
#include <stdint.h> 

int		main(void)
{
	setlocale(LC_ALL, "");
	
	printf("\nme ret = %d\n", ft_printf("%4.15d", -424242));
	
	printf("\nret = %d\n", printf("%4.15d", -424242));
 

	return (0);
}

