/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_compt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:03:40 by amaach            #+#    #+#             */
/*   Updated: 2019/12/15 21:13:53 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_trait_hexa_ma(size_t nb)
{
	if (nb == 10)
		ft_putchar('A');
	if (nb == 11)
		ft_putchar('B');
	if (nb == 12)
		ft_putchar('C');
	if (nb == 13)
		ft_putchar('D');
	if (nb == 14)
		ft_putchar('E');
	if (nb == 15)
		ft_putchar('F');
	g_compt++;
}

void	ft_trait_hexa_m(size_t nb)
{
	if (nb == 10)
		ft_putchar('a');
	if (nb == 11)
		ft_putchar('b');
	if (nb == 12)
		ft_putchar('c');
	if (nb == 13)
		ft_putchar('d');
	if (nb == 14)
		ft_putchar('e');
	if (nb == 15)
		ft_putchar('f');
	g_compt++;
}

void	ft_put16(size_t nb, int m)
{
	ft_puthexa_compt(nb / 16, m);
	if (nb % 16 > 9)
	{
		if (m)
			ft_trait_hexa_ma(nb % 16);
		else
			ft_trait_hexa_m(nb % 16);
	}
	else
		ft_putchar(nb % 16 + '0');
	g_compt++;
}

void	ft_puthexa_compt(size_t h, int m)
{
	size_t	nb;

	nb = h;
	if (nb >= 16)
		ft_put16(nb, m);
	else
	{
		if (nb % 16 > 9)
		{
			if (m)
				ft_trait_hexa_ma(nb % 16);
			else
				ft_trait_hexa_m(nb % 16);
		}
		else
			ft_putchar(nb + '0');
		g_compt++;
	}
}
