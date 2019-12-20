/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:20:30 by amaach            #+#    #+#             */
/*   Updated: 2019/12/20 21:17:51 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_traitement_str_moin_prec(char *str)
{
	int	j;

	j = 0;
	while (j < g_prec)
	{
		ft_putchar(str[j]);
		j++;
	}
	while (j < g_width)
	{
		ft_putchar(' ');
		j++;
	}
}

void	ft_traitement_str_moin(char *str)
{
	int		j;

	j = 0;
	while (str[j] != '\0')
	{
		ft_putchar(str[j]);
		j++;
		
	}
	while (j++ < g_width)
		ft_putchar(' ');
}

void	ft_traitement_str__prec(char *str, int len)
{
	int		j;

	j = 0;
	if (g_prec < len && g_prec > 0)
	{
		while (g_width - g_prec > 0)
		{
			ft_putchar(' ');
			g_width--;
		}
		while (j < g_prec)
		{
			ft_putchar(str[j]);
			j++;
		}
	}
	else
	{
		while (g_width - len > 0)
		{
			ft_putchar(' ');
			g_width--;
		}
		while (j < len)
		{
			ft_putchar(str[j]);
			j++;
		}
	}
}

void	ft_traitement_str_(char *str, int len)
{
	int		j;

	j = 0;

	if (g_prec < len && g_width > g_prec && g_prec > 0)
	{
		while (g_width - g_prec > 0)
		{
			ft_putchar(' ');
			g_width--;
		}
		while (j < g_prec)
		{
			ft_putchar(str[j]);
			j++;
		}
	}
	else if (g_prec < len && g_prec > 0)
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

int		ft_traitement_str(va_list list, int i)
{
	char	*str;
	int		len;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	len = 0;
	len = ft_strlen(str);
	if ((g_width == 0) && (g_prec == 0) && (g_dot == 0))
		ft_putstr(str);
	else if (g_dot && (g_prec == 0))
		ft_less_dot();
	else if (g_moin)
		ft_lol_lol(str, len);
	else
	{
		if (g_width)
		{
			if (g_width > len)
				ft_traitement_str__prec(str, len);
			else
				ft_traitement_str_(str, len);
		}
		else
			ft_traitement_putstr_prec(str, len);
	}
	return (i + 1);
}
