/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funx2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:10:50 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/04 20:45:27 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		utf_len(wchar_t *wide)
{
	int		i;
	int		j;

	i = 0;
	while (wide[i] != 0)
	{
		if (wide[i] <= 0x78)
			j += 1;
		else if (wide[i] <= 0x1fff)
			j += 2;
		else if (wide[i] <= 0xffff)
			j += 3;
		else
			j += 4;
		i++;
	}
	printf("j = %d\n", j);
	return (j);
}
