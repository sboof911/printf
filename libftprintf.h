/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:18:44 by amaach            #+#    #+#             */
/*   Updated: 2019/12/13 18:42:24 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

int		g_compt;
int		g_zero;
int		g_width;
int		g_spider;
int		g_prec;
int		g_dot;
int		g_moin;

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
void	ft_ini(void);
void	ft_traitement_str_moin_prec(char *str);
void	ft_traitement_str_moin(char *str);
void	ft_traitement_str__prec(char *str);
void	ft_traitement_str_(char *str, int len);
void	ft_lol(int len, char *str);
int		ft_traitement_int(va_list list, int j);
int		ft_intlen(int j);
int		ft_putnbr_prec(int n, int i);
int		ft_putnbr_compt(int n);
void    ft_traitement_int_width(int len, int i, int n);
void	ft_traitement_int_moin(int len, int i, int n);
void	ft_traitment_int_prec(int n, int len);
void	ft_traitement_int_zero(int len, int i, int n);
void	ft_traitement_null(int n);


#endif