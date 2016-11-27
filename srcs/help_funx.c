/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:15:12 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/26 22:45:35 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		temp_not_null(conv_obj *temp)
{
	if ( 	
			temp->minus == 0 &&
			temp->plus == 0 &&
			temp->hash == 0 &&
			temp->space == 0 &&
			temp->zero == 0 &&
			temp->len_f == 0 &&
			temp->con_typ == 0 &&
			temp->width == 0 &&
			temp->w_star == 0 &&
			temp->prec == 1 &&
			temp->p_star == 0 &&
			temp->str == 0
		)
		return (0);
	return (1);
}

int		ft_strc(char *str, char c)
{
	if (DEBUG) printf("ft_strc: in: str = %s c = %c\n", str, c);
	int		i;
	if (str == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_itoa3(long long nbr)
{
	if (DEBUG_D) printf("ft_itoa3: in\n");
	char	*ans;
	int		i;
	long long	n;

	n = nbr;
	i = ft_numlen(n);
	if (n < 0)
		n = n * -1;
	ans = (char *)malloc(sizeof(char) * (i + 1));
	if (ans == 0)
		return (NULL);
	ans[i] = '\0';
	if (n == 0)
		ans[--i] = 48;
	while (n != 0)
	{
		ans[--i] = n % 10 + 48;
		n = n / 10;
	}
	if (i != 0)
		ans[0] = '-';
	return (ans);
}

char		*ft_itoa_base(unsigned long long n, int base)
{
	if (DEBUG_o) printf("ft_itoa_base: in: n = %lld\n", n);
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
		str[0] = 0;
		return (str);
	}
	while (n != 0)
	{
		if (DEBUG_o) printf("ft_itoa_base: i: %d\n", i);	
		str[--i] = lst[n % base];
		n = n / base;
	}
	if (DEBUG_o) printf("ft_itoa_base: out: %s\n", str);	
	return (str);
}

int			ft_numlen_base(long long n, int base)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}



























































