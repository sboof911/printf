/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:34:59 by amaach            #+#    #+#             */
/*   Updated: 2019/12/20 20:47:42 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*temp;
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)s;
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
