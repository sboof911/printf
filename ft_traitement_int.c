/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:58:00 by amaach            #+#    #+#             */
/*   Updated: 2019/12/22 15:27:06 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_traitement_int_zero(int len, int i, int n)
{
	if (g_width > len && g_dot == 0)
	{
		if (n < 0)
			ft_putchar('-');
		while (i < g_width - len)
		{
			ft_putchar('0');
			i++;
		}
	}
	else if (g_width > len && g_dot == 1)
	{
		while (i < g_width - len)
			i = ft_put(i);
	}
	else if (g_prec == 0 && g_dot && n == 0)
		i = ft_put(i);
	if (n < 0 && !(g_width > len && g_dot == 0))
		ft_putchar('-');
	ft_putnbr_compt(n);
}

void	ft_traitment_int_prec(int n, int len)
{
	int		i;

	i = 0;
	if (g_prec == 0 && g_dot && n == 0)
		write(1, "", 0);
	else if (g_prec < len)
	{
		if (n < 0 && !g_moin)
			ft_putchar('-');
		ft_putnbr_compt(n);
	}
	else
	{
		if (n < 0 && !g_moin)
		{
			ft_putchar('-');
			g_prec++;
		}
		while (i < g_prec - len)
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr_compt(n);
	}
}

int		ft_intlen(int j)
{
	int		i;

	i = 0;
	if (j < 0)
	{
		j *= -1;
		i++;
	}
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
	{
		ft_putchar('-');
		g_prec++;
	}
	if (g_width > len)
		ft_someint(len, i, n);
	else
	{
		if (g_prec > len)
		{
			ft_traitment_int_prec(n, len);
			while (i < g_width - g_prec)
				i = ft_put(i);
		}
		else
			ft_putnbr_compt(n);
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
	if (n == -2147483648)
		len = 11;
	if (g_prec == 0 && n == 0 && g_dot)
		ft_traitement_null(n);
	else if (g_zero && !g_prec && !g_moin)
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
			ft_lool2(n);
	}
	return (j + 1);
}
