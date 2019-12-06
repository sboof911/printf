/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:02:20 by amaach            #+#    #+#             */
/*   Updated: 2019/12/04 21:38:46 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;

	va_start(list, s);
	i = 0;
	i = ft_initialisation(s, i);
	ft_traitement(s, i, list);
	va_end(list);
	return (compt);
}
