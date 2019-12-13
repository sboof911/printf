/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_int2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:52:31 by amaach            #+#    #+#             */
/*   Updated: 2019/12/13 18:42:09 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_traitement_int_width(int len, int i, int n)
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
			ft_traitment_int_prec(n, len);
		}
		else
			ft_traitment_int_prec(n, len);
	}
	else
	{
		while (i < g_width - len)
		{
			ft_putchar(' ');
			g_compt++;
			i++;
		}
		ft_putnbr_compt(n);
	}
}

void	ft_traitement_null(int n)
{
	if (n == 0)
		write(1, "", 0);
	else
		ft_putnbr_compt(n);
}
