/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traitement_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:20:30 by amaach            #+#    #+#             */
/*   Updated: 2019/12/04 21:32:51 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int		ft_traitement_str(va_list list, int i)
{
	int		j;
	char	*str;
	int		len;

	str = va_arg(list, char *);
	len = 0;
	j = 0;
	len = ft_strlen(str);
	if (moin)
	{
		if (width > j)
		{
			if (prec)
			{
				while (str[j] != '\0' && j < prec)
				{
					ft_putchar(str[j++]);
					compt++;
				}
				while (j < width)
				{
					ft_putchar(' ');
					compt++;
					j++;
				}
			}
			else
			{
				while (str[j] != '\0')
				{
					ft_putchar(' ');
					compt++;
					j++;
				}
			}
		}
	}
	return (i + 1);
}
