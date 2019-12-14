/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:58:00 by amaach            #+#    #+#             */
/*   Updated: 2019/12/14 16:18:35 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_traitement_int_zero(int len, int i, int n)
{
	if (g_width > len && !g_dot)
	{
		if (n < 0)
		{
			ft_putchar('-');
			g_compt++;
		}
		while (i < g_width - len)
		{
			ft_putchar('0');
			i++;
			g_compt++;
		}
	}
	if (g_width > len && g_dot)
	{
		i = ft_ifnega(i, n);
		while (i < g_width - len)
			i = ft_put(i);
	}
	ft_putnbr_compt(n);
}

void	ft_traitment_int_prec(int n, int len)
{
	int		i;

	i = 0;
	if (g_prec < len)
		ft_putnbr_compt(n);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			g_compt++;
		}
		while (i < g_prec - len)
		{
			ft_putchar('0');
			i++;
			g_compt++;
		}
		ft_putnbr_compt(n);
	}
}

int		ft_intlen(int j)
{
	int		i;

	i = 0;
	if (j < 0)
		j *= -1;
	while (j >= 10)
	{
		j /= 10;
		i++;
	}
	if (j < 10 && j >= 0)
		i++;
	return (i);
}

void	ft_traitement_int_moin(int len, int i, int n)
{
	if (n < 0)
		ft_putchar('-');
	if (g_width > len)
	{
		if (g_prec > len)
		{
			ft_traitment_int_prec(n, len);
			i = ft_ifnega(i, n);
			while (i < g_width - g_prec)
				i = ft_put(i);
		}
		else
		{
			ft_putnbr_compt(n);
			i = ft_ifnega(i, n);
			while (i < g_width - len)
				i = ft_put(i);
		}
	}
}

int		ft_traitement_int(va_list list, int j)
{
	int		n;
	int		len;
	int		i;

	i = 0;
	n = va_arg(list, int);
	len = ft_intlen(n);
	if (g_width == 0 && g_prec == 0)
		ft_traitement_null(n);
	else if (g_zero && !g_prec)
		ft_traitement_int_zero(len, i, n);
	else if (g_moin)
		ft_traitement_int_moin(len, i, n);
	else if (g_width)
		ft_traitement_int_width(len, i, n);
	else
	{
		if (g_prec > len)
			ft_traitment_int_prec(n, len);
		else
			ft_putnbr_compt(n);
	}
	return (j + 1);
}
