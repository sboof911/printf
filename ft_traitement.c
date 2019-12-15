/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:30:24 by amaach            #+#    #+#             */
/*   Updated: 2019/12/15 18:50:28 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_traitement_width(const char *s, int i, va_list list)
{
	if (s[i] == '-')
	{
		g_moin = 1;
		while (s[i] == '-')
			i++;
	}
	else if (s[i] == '0')
	{
		g_zero = 1;
		i++;
	}
	if (ft_isdigit(s[i]))
	{
		g_width = ft_atoi(s + i);
		while (ft_isdigit(s[i]))
			i++;
	}
	else if (s[i++] == '*')
		g_width = va_arg(list, int);
	if (g_width < 0)
	{
		g_moin = 1;
		g_width = g_width * -1;
	}
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
	while (s[i] != '\0')
	{
		i = ft_initialisation(s, i);
		if (s[i++] == '%')
		{
			if (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '0' || s[i] == '*')
				i = ft_traitement_width(s, i, list);
			if (s[i] == '.')
				i = ft_traitement_prec(s, i, list);
		}
		if (ft_check(s, i))
			i = ft_checkspec(s, i, list);
	}
}
