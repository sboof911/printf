/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 03:44:59 by amaach            #+#    #+#             */
/*   Updated: 2019/12/20 15:01:19 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	e;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < i / 2)
	{
		e = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = e;
		j++;
	}
	return (str);
}
