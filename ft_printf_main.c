/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:09:46 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/17 18:59:21 by zsmith           ###   ########.fr       */
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
	
	ft_printf("%b", 42424);
	// printf("\n%4.15d", 424242);
 

	return (0);
}

