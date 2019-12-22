/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_adresse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:44:13 by amaach            #+#    #+#             */
/*   Updated: 2019/12/22 15:01:06 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_adresse_zero(int len, int i, unsigned long long n, int m)
{
	if (g_width > len && g_dot == 0)
	{
		while (i < g_width - len)
		{
			ft_putchar('0');
			i++;
		}
	}
	if (g_width > len && g_dot)
	{
		while (i < g_width - len)
			i = ft_put(i);
	}
	if (g_prec == 0 && g_dot && n == 0)
		i = ft_put(i);
	else
		ft_puthexa_compt(n, m);
}

void	ft_adresse_prec(unsigned long long n, int len, int m)
{
	int		i;

	i = 0;
	if (g_prec == 0 && g_dot && n == 0)
		write(1, "", 0);
	else if (g_prec < len)
		ft_puthexa_compt(n, m);
	else
	{
		while (i < g_prec - len)
		{
			ft_putchar('0');
			i++;
		}
		ft_puthexa_compt(n, m);
	}
}

int		ft_adresselen(unsigned long long j)
{
	int	i;

	i = 0;
	while (j >= 16)
	{
		j /= 16;
		i++;
	}
	if (j < 16)
		i++;
	return (i);
}

void	ft_adresse_moin(int len, int i, unsigned long long n, int m)
{
	if (g_width > len)
	{
		if (g_prec > len)
			ft_somehexa(len, i, n, m);
		else
		{
			ft_puthexa_compt(n, m);
			while (i < g_width - len)
				i = ft_put(i);
		}
	}
	else
	{
		if (g_prec > len)
		{
			ft_adresse_prec(n, len, m);
			while (i < g_width - g_prec)
				i = ft_put(i);
		}
		else
			ft_puthexa_compt(n, m);
	}
}

int		ft_adresse(va_list list, int j, int m)
{
	unsigned long long	n;
	int					len;
	int					i;

	i = 0;
	n = va_arg(list, unsigned long long);
	g_width = g_width - 2;
	len = ft_adresselen(n);
	if (g_prec == 0 && n == 0 && g_dot)
		ft_adresse_null(n, m);
	else if (g_zero && !g_prec && !g_moin)
		ft_adresse_zero(len, i, n, m);
	else if (g_moin)
		ft_adresse_moin(len, i, n, m);
	else if (g_width)
		ft_adresse_width(len, i, n, m);
	else
	{
		if (g_prec > len)
			ft_adresse_prec(n, len, m);
		else
			ft_puthexa_compt(n, m);
	}
	return (j + 1);
}
