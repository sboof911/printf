/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_u2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:14:50 by amaach            #+#    #+#             */
/*   Updated: 2019/12/21 20:27:29 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_traitement_u_width(int len, int i, unsigned int n)
{
	if (g_prec > len)
	{
		if (g_prec < g_width)
		{
			i = ft_ifnega(i, n);
			while (i < g_width - g_prec)
				i = ft_put(i);
			ft_traitment_u_prec(n, len);
		}
		else
			ft_traitment_u_prec(n, len);
	}
	else
	{
		while (i < g_width - len)
			i = ft_put(i);
		ft_putnbr_u_compt(n);
	}
}

void	ft_traitement_u_null(unsigned int n)
{
	if ((n == 0) && !g_width && !g_prec && !g_dot)
		ft_putchar('0');
	else if ((n == 0) && g_width == 0 && g_prec == 0 && g_dot)
		write(1, "", 0);
	else if (g_width > 0 && n == 0 && !g_prec && g_dot)
	{
		while (g_width--)
			ft_putchar(' ');
	}
	else
		ft_putnbr_u_compt(n);
}

void	ft_some_u(int len, int i, unsigned int n)
{
	if (g_prec > len)
	{
		ft_traitment_u_prec(n, len);
		while (i < g_width - g_prec)
			i = ft_put(i);
	}
	else
	{
		ft_putnbr_u_compt(n);
		while (i < g_width - len)
			i = ft_put(i);
	}
}

int		ft_u_len(unsigned int j)
{
	int		i;

	i = 0;
	while (j >= 10)
	{
		j /= 10;
		i++;
	}
	if (j < 10)
		i++;
	return (i);
}
