/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:14:11 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/12 19:02:50 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcat_c(char *s1, char s2)
{
	char			*ret;
	int				i;

	ret = ft_memalloc(ft_strlen(s1) + 2);
	ft_strcpy((char *)ret, s1);
	i = 0;
	while (((char *)s2)[i])
	{
		((char *)ret)[ft_strlen((char *)s1) + i] = ((char *)s2)[i];
		i++;
	}
	((char *)ret)[i + ft_strlen(s2) + 1] = '\0';
	return (ret);
}
