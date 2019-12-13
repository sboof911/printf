/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_str2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:37:24 by amaach            #+#    #+#             */
/*   Updated: 2019/12/13 20:53:44 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_traitement_putstr_prec(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0' && j < g_prec)
	{
		ft_putchar(str[j]);
		g_compt++;
		j++;
	}
}

void	ft_lol_lol(char *str, int len)
{
	if (g_width > len || g_width > g_prec)
		ft_lol(len, str);
	else
		ft_traitement_putstr_prec(str);
}
