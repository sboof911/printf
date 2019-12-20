/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:12:30 by amaach            #+#    #+#             */
/*   Updated: 2019/12/20 15:01:19 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ft_str(int n, long a, int i, int sign)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (ft_len(n) + 1))))
		return (0);
	while (a > 0)
	{
		str[i] = a % 10 + '0';
		a /= 10;
		i++;
	}
	if (sign)
		str[i++] = '-';
	str[i++] = '\0';
	ft_strrev(str);
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		sign;
	long	a;

	sign = 0;
	i = 0;
	a = n;
	if (n == 0)
		return ("0");
	if (n < 0)
	{
		sign = n;
		a *= -1;
	}
	return (ft_str(n, a, i, sign));
}
