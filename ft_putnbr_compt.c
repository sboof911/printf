/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_compt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:19:06 by amaach            #+#    #+#             */
/*   Updated: 2019/12/13 21:09:24 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_compt(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
		g_compt++;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr_compt(nb / 10);
		ft_putchar(nb % 10 + '0');
		g_compt++;
	}
	else
	{
		ft_putchar(nb + '0');
		g_compt++;
	}
}
