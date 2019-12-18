/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_adresse2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:44:05 by amaach            #+#    #+#             */
/*   Updated: 2019/12/18 15:01:56 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_adresse_width(int len, int i, size_t n, int m)
{
	if (g_prec > len)
	{
		if (g_prec < g_width)
		{
			while (i < g_width - g_prec)
			{
				ft_putchar(' ');
				g_compt++;
				i++;
			}
			ft_adresse_prec(n, len, m);
		}
		else
			ft_adresse_prec(n, len, m);
	}
	else
	{
		while (i < g_width - len)
		{
			ft_putchar(' ');
			g_compt++;
			i++;
		}
		ft_puthexa_compt(n, m);
	}
}

void	ft_adresse_null(size_t n, int m)
{
	if (n == 0)
		write(1, "", 0);
	else
		ft_puthexa_compt(n, m);
}

void	ft_someadresse(int len, int i, size_t n, int m)
{
	ft_adresse_prec(n, len, m);
	while (i < g_width - g_prec)
		i = ft_put(i);
}
