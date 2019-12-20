/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_hexa2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:58:02 by amaach            #+#    #+#             */
/*   Updated: 2019/12/20 18:14:30 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_traitement_hexa_width(int len, int i, unsigned int n, int m)
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
			ft_traitment_hexa_prec(n, len, m);
		}
		else
			ft_traitment_hexa_prec(n, len, m);
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

void	ft_traitement_hexa_null(unsigned int n, int m)
{
	if ((n == 0) & g_width & g_prec)
		write(1, "", 0);
	else
		ft_puthexa_compt(n, m);
}

void	ft_somehexa(int len, int i, unsigned int n, int m)
{
	ft_traitment_hexa_prec(n, len, m);
	while (i < g_width - g_prec)
		i = ft_put(i);
}
