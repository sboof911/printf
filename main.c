/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:33:42 by amaach            #+#    #+#             */
/*   Updated: 2019/12/17 18:45:02 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"



int		main()
{
	int		i;
	//i = ft_printf("10.4%p\n", (void *) 12327);
	//printf("%d\n", i);
	//printf("lol\n");
	printf("%u", 515151);
	ft_printf("%%");
	return (0);
}