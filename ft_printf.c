/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:02:20 by amaach            #+#    #+#             */
/*   Updated: 2019/12/23 11:45:08 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;

	g_compt = 0;
	g_fault = 0;
	va_start(list, s);
	i = 0;
	ft_traitement(s, i, list);
	va_end(list);
	if (g_fault == 1)
		return (-1);
	return (g_compt);
}
