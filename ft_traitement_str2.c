/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_str2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:37:24 by amaach            #+#    #+#             */
/*   Updated: 2019/12/20 21:12:30 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_traitement_putstr_prec(char *str, int len)
{
	int	j;

	j = 0;
	
	if (g_prec < len && g_prec > 0)
	{
		while (j < g_prec)
		{
			ft_putchar(str[j]);
			j++;
		}
	}
	else
		ft_putstr(str);
}

void	ft_lol_lol(char *str, int len)
{
	if (g_width)
		ft_lol(len, str);
	else
		ft_traitement_putstr_prec(str, len);
}

void	ft_lol(int len, char *str)
{
	if (g_width > len)
	{
		if (g_prec < len && g_prec > 0)
			ft_traitement_str_moin_prec(str);
		else
			ft_traitement_str_moin(str);
	}
	else
	{
		if (g_prec < len && g_width > g_prec && g_prec > 0)
			ft_traitement_str_moin_prec(str);
		else
			ft_traitement_putstr_prec(str, len);
	}
}

void	ft_less_dot(void)
{
	int		i;

	i = 0;
	if (g_width)
	{
		while (i++ < g_width)
			ft_putchar(' ');
	}
	else
		write(0, "", 1);
}