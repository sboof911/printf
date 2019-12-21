/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_adresse2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:44:05 by amaach            #+#    #+#             */
/*   Updated: 2019/12/21 21:51:06 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_adresse_width(int len, int i, unsigned long long n, int m)
{
	if (g_prec > len)
	{
		if (g_prec < g_width)
		{
			while (i < g_width - g_prec)
			{
				ft_putchar(' ');
				
				i++;
			}
			ft_adresse_prec(n, len, m);
		}
		else
			ft_adresse_prec(n, len, m);
	}
	else
	{
		while (i < g_width - len)
		{
			ft_putchar(' ');
			
			i++;
		}
		ft_puthexa_compt(n, m);
	}
}

void	ft_adresse_null(unsigned long long n, int m)
{
	if (g_width == -1)
		g_width++;
	if (g_width == -2)
		g_width += 2;
	if ((n == 0) && !g_width && !g_prec && !g_dot)
		ft_puthexa_compt('0', m);
	else if ((n == 0) && g_width == 0 && g_prec == 0 && g_dot)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
	else if (g_width > 0 && n == 0 && !g_prec && g_dot && !g_moin)
	{
		while (g_width--)
			ft_putchar(' ');
		ft_putchar('0');
		ft_putchar('x');
	}
	else if (g_width > 0 && n == 0 && !g_prec && g_dot && g_moin)
	{
		ft_putchar('0');
		ft_putchar('x');
		while (g_width--)
			ft_putchar(' ');

	}
}

void	ft_someadresse(int len, int i, unsigned long long n, int m)
{
	ft_adresse_prec(n, len, m);
	while (i < g_width - g_prec)
		i = ft_put(i);
}
