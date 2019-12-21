/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:33:42 by amaach            #+#    #+#             */
/*   Updated: 2019/12/21 21:48:53 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"



int		main()
{
	int		i;
	i = ft_printf("Bla bla %*.p", -15, 0);
	//printf("%%%%%10c", 'c');
	//printf("lol\n");
	//printf("%10.10c", 'c');
	//printf("\n%10.10s", "c");
	printf ("\n%d", i);
	printf("\n\n\n");
	printf("Bla bla %*.p", -15, (void *) 0);
	return (0);
}