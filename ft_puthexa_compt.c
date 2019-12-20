/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_compt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:03:40 by amaach            #+#    #+#             */
/*   Updated: 2019/12/20 18:32:58 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_trait_hexa_ma(unsigned long long nb)
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
	
}

void	ft_trait_hexa_m(unsigned long long nb)
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
	
}

void	ft_put16(unsigned long long nb, int m)
{
	int		i = 0;

i++;
	ft_puthexa_compt(nb / 16, m);
	if (nb % 16 > 9)
	{
		if (m)
			ft_trait_hexa_ma(nb % 16);
		else
			ft_trait_hexa_m(nb % 16);
	}
	else
	{
		ft_putchar(nb % 16 + '0');
	}
}

void	ft_puthexa_compt(unsigned long long h, int m)
{
	unsigned long long	nb;

	nb = h;
	ft_ifp();
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
	}
}

void	ft_ifp(void)
{
	if (g_p == 1)
	{
		ft_putchar('0');
		ft_putchar('x');
		g_p = 0;
	}
}
