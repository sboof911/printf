/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_compt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:19:06 by amaach            #+#    #+#             */
/*   Updated: 2019/12/12 15:18:16 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putnbr_compt(int n)
{
	unsigned int	nb;
	int				compt;

	compt = 0;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
		compt++;
	}
	else
		nb = n;
	if (n >= 10)
	{
		ft_putnbr_compt(nb / 10);
		ft_putchar(nb % 10 + '0');
		compt++;
	}
	else
	{
		ft_putchar(nb + '0');
		compt++;
	}
	g_compt = g_compt + compt;
	return (compt);
}

void	repeat_char(char c, int nb)
{
	while (nb > 0)
	{
		ft_putchar(c);
		nb--;
		g_compt++;
	}
}
