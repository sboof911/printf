/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:14:06 by amaach            #+#    #+#             */
/*   Updated: 2019/12/17 18:34:20 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lol(int len, char *str)
{
	if (g_dot && g_prec < len)
		ft_traitement_str_moin_prec(str);
	else
		ft_traitement_str_moin(str);
}

void	ft_ini(void)
{
	g_zero = 0;
	g_width = 0;
	g_spider = 0;
	g_prec = 0;
	g_dot = 0;
	g_moin = 0;
	g_m = 0;
	g_p = 0;
}

int		ft_initialisation(const char *s, int i)
{
	ft_ini();
	while (s[i] != '%' && s[i] != '\0')
	{
		ft_putchar(s[i]);
		g_compt++;
		i++;
	}
	return (i);
}
