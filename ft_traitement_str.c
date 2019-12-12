/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:20:30 by amaach            #+#    #+#             */
/*   Updated: 2019/12/10 14:54:30 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_traitement_str_moin_prec(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0' && j < g_prec)
	{
		ft_putchar(str[j]);
		g_compt++;
		j++;
	}
	while (j < g_width)
	{
		ft_putchar(' ');
		g_compt++;
		j++;
	}
}

void	ft_traitement_str_moin(char *str)
{
	int		j;

	j = 0;
	while (str[j] != '\0' && g_width-- > 0)
	{
		ft_putchar(str[j]);
		j++;
		g_compt++;
	}
	while (g_width-- > 0)
	{
		ft_putchar(' ');
		g_compt++;
	}
}

void	ft_traitement_str__prec(char *str)
{
	int		j;

	j = 0;
	while (g_width - g_prec > 0)
	{
		ft_putchar(' ');
		g_compt++;
		g_width--;
	}
	while (j < g_prec)
	{
		ft_putchar(str[j]);
		g_compt++;
		j++;
	}
}

void	ft_traitement_str_(char *str, int len)
{
	int		j;

	j = 0;

	while (g_width - len > 0)
	{
		ft_putchar(' ');
		g_compt++;
		g_width--;
	}
	while (j < g_width)
	{
		ft_putchar(str[j]);
		g_compt++;
		j++;
	}
}

int		ft_traitement_str(va_list list, int i)
{
	char	*str;
	int		len;

	str = va_arg(list, char *);
	len = 0;
	len = ft_strlen(str);
	if (g_moin)
	{
		if (g_width > len)
			ft_lol(len, str);
	}
	else
	{
		if (g_width > len)
		{
			if (g_dot && g_prec < len)
				ft_traitement_str__prec(str);
			else
				ft_traitement_str_(str, len);
		}
	}
	return (i + 1);
}
