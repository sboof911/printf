/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:58:00 by amaach            #+#    #+#             */
/*   Updated: 2019/12/12 15:28:23 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int		ft_traitement_int(va_list list, int j)
{
	int		n;
	int		len;
	char	c;
	int		i;

	i = 0;
	n = va_arg(list, int);
	len = ft_intlen(j);
	if (g_moin)
	{
		if (g_width > len)
		{
			if (g_dot && g_prec < len)
			{
				i = ft_putnbr_prec(n, i);
				while (i < g_width)
				{
					ft_putchar(' ');
					g_compt++;
					i++;
				}
			}
			else
			{
				i = ft_putnbr_compt(n);
				while (i < g_width)
				{
					ft_putchar(' ');
					g_compt++;
					i++;
				}
			}
		}
		else
		{
			if (g_dot && g_prec < len)
			{
				if (g_prec < g_width)
				{
					i = ft_putnbr_prec(n, i);
					while (i < g_width)
					{
						ft_putchar(' ');
						g_compt++;
						i++;
					}
				}
				else
					i = ft_putnbr_prec(n, i);
			}
			else
				i = ft_putnbr_compt(n);
		}
	}
	else
	{
		c = ' ';
		if (g_zero)
			c = '0';
		if (g_width > len)
		{
			if (g_dot && g_prec < len)
			{
				while (i < g_width - g_prec)
				{
					ft_putchar(c);
					g_compt++;
					i++;
				}
				i = ft_putnbr_prec(n, i);
			}
			else
			{
				while (i < g_width - len)
				{
					ft_putchar(c);
					g_compt++;
					i++;
				}
				i = ft_putnbr_compt(n);
			}
		}
		else
		{
			if (g_dot && g_prec < len)
			{
				if (g_prec < g_width)
				{
					while (i < g_width - g_prec)
					{
						ft_putchar(c);
						g_compt++;
						i++;
					}
					i = ft_putnbr_prec(n, i);
				}
				else
					i = ft_putnbr_prec(n, i);
			}
			else
				i = ft_putnbr_compt(n);
		}
	}
	return (j + 1);
}
