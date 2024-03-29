/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:22:17 by amaach            #+#    #+#             */
/*   Updated: 2019/12/20 15:01:19 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if ((unsigned char)c > 47 && (unsigned char)c < 58)
		return (1);
	return (0);
}
