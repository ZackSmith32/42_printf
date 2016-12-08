/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:15:12 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/08 13:51:20 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


static int		ft_numlen_base(unsigned long long n, int base)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

static unsigned long long	ft_abs(long long num)
{
	unsigned long long z;

	if (num < 0)
		z = num * -1;
	else
		z = num;
	return (z);
}

char		*ft_itoa3(long long nbr)
{
	char				*ans;
	int					i;
	unsigned long long	n;
	int					neg;

	neg = 0;
	if (nbr < 0)
		neg = 1;
	n = ft_abs(nbr);
	i = ft_numlen_base(n, 10) + (neg == 1 ? 1 : 0);
	ans = (char *)malloc(sizeof(char) * (i + 1));
	ans[i] = '\0';
	if (n == 0)
		ans[--i] = 48;
	while (n != 0)
	{
		ans[--i] = n % 10 + 48;
		n = n / 10;
	}
	if (neg == 1)
		ans[0] = '-';
	return (ans);
}



char		*ft_itoa_base(unsigned long long n, int base)
{
	int		i;
	char 	lst[17];
	char	*str;

	ft_strcpy(lst, "0123456789abcdef");
	i = ft_numlen_base(n, base);
	str = ft_memalloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n != 0)
	{
		str[--i] = lst[n % base];
		n = n / base;
	}
	return (str);
}

int		utf_len(wchar_t *wide)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
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
	return (j);
}
