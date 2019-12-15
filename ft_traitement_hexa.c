/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:48:50 by amaach            #+#    #+#             */
/*   Updated: 2019/12/15 18:48:05 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_traitemt_hexa_zero(unsigned int len, size_t i, unsigned int n, int m)
{
	if (g_width > len && g_dot == 0)
	{
		while (i < g_width - len)
		{
			ft_putchar('0');
			i++;
			g_compt++;
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

void	ft_traitment_hexa_prec(unsigned int n, unsigned int len, int m)
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
			g_compt++;
		}
		ft_puthexa_compt(n, m);
	}
}

int		ft_hexalen(unsigned int j)
{
	unsigned int	i;

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

void	ft_traitemt_hexa_moin(unsigned int len, size_t i, unsigned int n, int m)
{
	if (g_width > len)
	{
		if (g_prec > len)
		{
			ft_traitment_hexa_prec(n, len, m);
			while (i < g_width - g_prec)
				i = ft_put(i);
		}
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
			ft_traitment_hexa_prec(n, len, m);
			while (i < g_width - g_prec)
				i = ft_put(i);
		}
		else
			ft_putnbr_compt(n);
	}
}

int		ft_traitement_hexa(va_list list, int j, int m)
{
	unsigned int	n;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	n = va_arg(list, unsigned int);
	len = ft_hexalen(n);
	if (g_width == 0 && g_prec == 0)
		ft_traitement_hexa_null(n, m);
	else if (g_zero && !g_prec)
		ft_traitemt_hexa_zero(len, i, n, m);
	else if (g_moin)
		ft_traitemt_hexa_moin(len, i, n, m);
	else if (g_width)
		ft_traitemt_hexawidth(len, i, n, m);
	else
	{
		if (g_prec > len)
			ft_traitment_hexa_prec(n, len, m);
		else
			ft_puthexa_compt(n, m);
	}
	return (j + 1);
}
