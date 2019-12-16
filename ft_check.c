/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:34:23 by amaach            #+#    #+#             */
/*   Updated: 2019/12/13 21:48:22 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_checkspec(const char *s, int i, va_list list)
{
	int		m;

	m = 0;
	if (s[i] == 's')
		i = ft_traitement_str(list, i);
	/*else if (s[i] == 'c' || s[i] == '%')
		i = ft_traitement_char(s, list, i);*/
	else if (s[i] == 'd' || s[i] == 'i')
		i = ft_traitement_int(list, i);
	else if (s[i] == 'X' || s[i] == 'x')
	{
		if (s[i] == 'X')
			m = 1;
		i = ft_traitement_hexa(list, i, m);
	}
	/*else if (s[i] == 'p')
		i = ft_traitment_hexa(s, list, i);*/
	return (i);
}

int		ft_check(const char *s, int i)
{
	if (s[i] == 'd' || s[i] == 's' || s[i] == '%' || s[i] == 'i' || s[i] == 'c'
			|| s[i] == 'X' || s[i] == 'p' || s[i] == 'x')
		return (1);
	return (0);
}