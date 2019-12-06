/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:18:44 by amaach            #+#    #+#             */
/*   Updated: 2019/12/04 21:32:58 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

int		compt;
int		zero;
int		width;
int		spider;
int		prec;
int		dot;
int		moin;

int		ft_atoi(const char *s);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
int		ft_printf(const char *s, ...);
void	ft_putchar(char c);
int		ft_traitement_width(const char *s, int i, va_list list);
int		ft_traitement_prec(const char *s, int i, va_list list);
void	ft_traitement(const char *s, int i, va_list list);
int		ft_checkspec(const char *s, int i, va_list list);
int		ft_check(const char *s, int i);
int		ft_initialisation(const char *s, int i);
int		ft_traitement_str(va_list list, int i);
char	*ft_strrev(char *str);
size_t	ft_strlen(const char *s);

#endif
