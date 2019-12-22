/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:18:07 by amaach            #+#    #+#             */
/*   Updated: 2019/12/22 15:52:09 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_traitement_char(va_list list, int i)
{
	int		c;
	int		j;

	j = 0;
	if (!g_p)
		c = va_arg(list, int);
	else
		c = '%';
	if (g_moin)
	{
		ft_putchar(c);
		if (g_width > 1)
		{
			while (j < g_width - 1)
				j = ft_put(j);
		}
	}
	else if (!g_zero)
		ft_char_zero(j, c);
	else if (c == '%')
		ft_char_lol(j, c);
	return (i + 1);
}

void	ft_char_lol(int j, int c)
{
	if (g_width > 1)
	{
		while (j < g_width - 1)
		{
			ft_putchar('0');
			j++;
		}
	}
	ft_putchar(c);
}

void	ft_char_zero(int j, int c)
{
	if (g_width > 1)
	{
		while (j < g_width - 1)
			j = ft_put(j);
	}
	ft_putchar(c);
}
