/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:54:28 by amaach            #+#    #+#             */
/*   Updated: 2019/12/12 14:32:13 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putnbr_prec(int n, int i)
{
	unsigned int	nb;
	int				compt;

	compt = 0;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
		compt++;
		i++;
	}
	else
		nb = n;
	if (nb >= 10 && i < g_prec)
	{
		ft_putnbr_prec(nb / 10, i);
		ft_putchar(nb % 10 + '0');
		compt++;
		i++;
	}
	return (i);
}
