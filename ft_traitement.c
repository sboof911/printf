/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:30:24 by amaach            #+#    #+#             */
/*   Updated: 2019/12/23 12:01:07 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_traitement_width(const char *s, int i, va_list list)
{
	if (s[i] == '-')
	{
		g_moin = 1;
		while (s[i] == '-')
			i++;
		i = ft_tr(s, i);
	}
	else if (s[i] == '0')
	{
		g_zero = 1;
		i++;
		i = ft_tr(s, i);
	}
	if (ft_isdigit(s[i]))
		i = ft_tr_w(s, i);
	else if (s[i] == '*')
	{
		g_width = va_arg(list, int);
		i++;
	}
	if (g_width < 0)
		ft_tr_width();
	return (i);
}

int		ft_traitement_prec(const char *s, int i, va_list list)
{
	g_dot = 1;
	i++;
	if (s[i] == '*')
	{
		g_prec = va_arg(list, int);
		if (g_prec < 0)
		{
			g_prec = 0;
			g_dot = 0;
		}
		i++;
	}
	else if (ft_isdigit(s[i]))
	{
		g_prec = ft_atoi(s + i);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}

void	ft_traitement(const char *s, int i, va_list list)
{
	int		len;
	int		pc;

	len = ft_strlen(s);
	while (i < len)
	{
		i = ft_initialisation(s, i);
		if (s[i] == '%')
		{
			while (s[i] == '%')
				i = ft_tr_pc(i);
			if (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '0' || s[i] == '*')
				i = ft_traitement_width(s, i, list);
			if (s[i] == '.')
				i = ft_traitement_prec(s, i, list);
		}
		if (g_pc > 1)
		{
			pc = g_pc / 2;
			while (pc--)
				ft_putchar('%');
		}
		if (ft_check(s, i) && (g_pc % 2 == 1))
			i = ft_checkspec(s, i, list);
	}
}

void	ft_tr_width(void)
{
	g_moin = 1;
	g_width = g_width * -1;
}

int		ft_tr_pc(int i)
{
	g_pc++;
	i++;
	return (i);
}
