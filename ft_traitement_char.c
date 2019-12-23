/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:18:07 by amaach            #+#    #+#             */
/*   Updated: 2019/12/23 18:33:44 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_traitement_char(va_list list, int i)
{
	int		c;
	int		j;

	j = 0;
	if (!g_p && !g_fault)
		c = va_arg(list, int);
	else
		c = '%';
	if (g_moin)
	{
		ft_putchar(c);
		if ((g_width > 1 && !g_fault) || (c == '%' && g_fault == 1
			&& g_width > 1))
		{
			if ((c == '%' && g_fault == 1 && g_width > 1))
				g_fault = 0;
			while (j < g_width - 1)
				j = ft_put(j);
		}
	}
	else if (!g_zero && !g_fault)
		ft_char_zero(j, c);
	else if (c == '%' && !g_fault)
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

int		ft_tr(const char *str, int i)
{
	int		compt_moin;
	int		compt_zero;

	compt_moin = 0;
	compt_zero = 0;
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '0')
			compt_zero++;
		else
			compt_moin++;
		i++;
	}
	if (compt_zero > 0 && compt_moin > 0)
	{
		g_fault = 1;
		g_moin = 1;
	}
	return (i);
}

int		ft_tr_w(const char *s, int i)
{
	g_width = ft_atoi(s + i);
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}
