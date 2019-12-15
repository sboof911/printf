/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_compt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:19:06 by amaach            #+#    #+#             */
/*   Updated: 2019/12/15 15:03:38 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_compt(int n)
{
	unsigned int	nb;
	int				len;

	len = ft_intlen(n);
	if (n < 0 && g_prec < len && g_width < len && g_dot)
	{
		nb = n * -1;
	}
	if (n < 0)
		nb = n * -1;
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
