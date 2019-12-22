/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:34:23 by amaach            #+#    #+#             */
/*   Updated: 2019/12/22 15:26:51 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkspec(const char *s, int i, va_list list)
{
	int		m;

	m = 0;
	if (s[i] == 's')
		i = ft_traitement_str(list, i);
	else if (s[i] == 'c' || s[i] == '%')
		i = ft_lool(s, list, i);
	else if (s[i] == 'd' || s[i] == 'i')
		i = ft_traitement_int(list, i);
	else if (s[i] == 'X' || s[i] == 'x')
	{
		if (s[i] == 'X')
			m = 1;
		i = ft_traitement_hexa(list, i, m);
	}
	else if (s[i] == 'p')
	{
		g_p = 1;
		i = ft_adresse(list, i, m);
	}
	else if (s[i] == 'u')
		i = ft_traitement_u(list, i);
	return (i);
}

int		ft_check(const char *s, int i)
{
	if (s[i] == 'd' || s[i] == 's' || s[i] == '%' || s[i] == 'i' || s[i] == 'c'
			|| s[i] == 'X' || s[i] == 'p' || s[i] == 'x' || s[i] == 'u')
		return (1);
	return (0);
}

int		ft_lool(const char *s, va_list list, int i)
{
	if (s[i] == '%')
		g_p = 1;
	i = ft_traitement_char(list, i);
	return (i);
}

void	ft_lool2(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_putnbr_compt(n);
}
