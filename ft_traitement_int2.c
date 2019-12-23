/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_int2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:52:31 by amaach            #+#    #+#             */
/*   Updated: 2019/12/21 16:16:31 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put(int i)
{
	ft_putchar(' ');
	i++;
	return (i);
}

int		ft_ifnega(int i, int n)
{
	if (n < 0)
		i++;
	return (i);
}

void	ft_traitement_int_width(int len, int i, int n)
{
	if (g_prec > len)
	{
		if (g_prec < g_width)
		{
			i = ft_ifnega(i, n);
			while (i < g_width - g_prec)
				i = ft_put(i);
			ft_traitment_int_prec(n, len);
		}
		else
			ft_traitment_int_prec(n, len);
	}
	else
	{
		while (i < g_width - len)
			i = ft_put(i);
		if (n < 0 && !g_moin)
			ft_putchar('-');
		ft_putnbr_compt(n);
	}
}

void	ft_traitement_null(int n)
{
	if ((n == 0) && !g_width && !g_prec && !g_dot)
		ft_putchar('0');
	else if ((n == 0) && g_width == 0 && g_prec == 0 && g_dot)
		write(1, "", 0);
	else if (g_width > 0 && n == 0 && !g_prec && g_dot)
	{
		while (g_width--)
			ft_putchar(' ');
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
		}
		ft_putnbr_compt(n);
	}
}

void	ft_someint(int len, int i, int n)
{
	if (g_prec > len)
	{
		ft_traitment_int_prec(n, len);
		while (i < g_width - g_prec)
			i = ft_put(i);
	}
	else
	{
		ft_putnbr_compt(n);
		while (i < g_width - len)
			i = ft_put(i);
	}
}
