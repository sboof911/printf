/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:13:56 by amaach            #+#    #+#             */
/*   Updated: 2019/12/21 20:27:00 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_traitement_u_zero(int len, int i, unsigned int n)
{
	if (g_width > len && g_dot == 0)
	{
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
	else
	{
	}
	ft_putnbr_u_compt(n);
}

void	ft_traitment_u_prec(unsigned int n, int len)
{
	int		i;

	i = 0;

	if (g_prec == 0 && g_dot && n == 0)
		write(1, "", 0);
	else if (g_prec < len)
	{
		ft_putnbr_u_compt(n);
	}
	else
	{
		while (i < g_prec - len)
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr_u_compt(n);
	}
}

void	ft_traitement_u_moin(int len, int i, unsigned int n)
{
	if (g_width > len)
		ft_some_u(len, i, n);
	else
	{
		if (g_prec > len)
		{
			ft_traitment_int_prec(n, len);
			while (i < g_width - g_prec)
				i = ft_put(i);
		}
		else
			ft_putnbr_u_compt(n);
	}
}

int		ft_traitement_u(va_list list, int j)
{
	unsigned int    n;
	int				len;
	int				i;

	i = 0;
	n = va_arg(list, unsigned int);
	len = ft_u_len(n);
	if (g_prec == 0 && n == 0 && g_dot)
		ft_traitement_u_null(n);
	else if (g_zero && !g_prec)
		ft_traitement_u_zero(len, i, n);
	else if (g_moin)
		ft_traitement_u_moin(len, i, n);
	else if (g_width)
		ft_traitement_u_width(len, i, n);
	else
	{
		if (g_prec > len)
			ft_traitment_u_prec(n, len);
		else
			ft_putnbr_u_compt(n);
	}
	return (j + 1);
}
