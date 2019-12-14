/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:02:20 by amaach            #+#    #+#             */
/*   Updated: 2019/12/09 16:58:13 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;

	g_compt = 0;
	va_start(list, s);
	i = 0;
	i = ft_initialisation(s, i);
	ft_traitement(s, i, list);
	va_end(list);
	return (g_compt);
}
