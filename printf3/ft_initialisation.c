/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:14:06 by amaach            #+#    #+#             */
/*   Updated: 2019/12/04 21:45:33 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_initialisation(const char *s, int i)
{
	compt = 0;
	zero = 0;
	width = 0;
	spider = 0;
	prec = 0;
	dot = 0;
	moin = 0;

	while (s[i] != '%')
	{
		ft_putchar(s[i]);
		compt++;
		i++;
	}
	return (i);
}
