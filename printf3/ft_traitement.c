/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:30:24 by amaach            #+#    #+#             */
/*   Updated: 2019/12/05 16:00:39 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_traitement_width(const char *s, int i, va_list list)
{
	if (s[i++] == '-')
		moin = 1;
	else if (s[i++] == '0')
		zero = 1;
	if (ft_isdigit(s[i]))
	{
		width = ft_atoi(s + i);
		while (ft_isdigit(i))
			i++;
	}
	else if (s[i++] == '*')
		width = va_arg(list, int);
	return (i);
}

int		ft_traitement_prec(const char *s, int i, va_list list)
{
	dot = 1;
	if (s[i++] == '*')
		prec = va_arg(list, int);
	else if (ft_isdigit(s[i]))
	{
		prec = ft_atoi(s + i);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}

void	ft_traitement(const char *s, int i, va_list list)
{
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i = ft_traitement_width(s, i, list);
			if (s[i++] == '.')
				i = ft_traitement_prec(s, i, list);
		}
		if (ft_check(s, i))
			i = ft_checkspec(s, i, list);
	}
}
