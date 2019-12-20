/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:18:44 by amaach            #+#    #+#             */
/*   Updated: 2019/12/20 21:11:39 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

int		g_compt;
int		g_zero;
int		g_width;
int		g_spider;
int		g_prec;
int		g_dot;
int		g_moin;
int     g_m;
int     g_pc;
int     g_p;

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
void	ft_traitement_str__prec(char *str, int len);
void	ft_traitement_str_(char *str, int len);
void	ft_lol(int len, char *str);
int		ft_traitement_int(va_list list, int j);
int		ft_intlen(int j);
int		ft_putnbr_prec(int n, int i);
void	ft_putnbr_compt(int n);
void    ft_putstr(char *str);
void    ft_traitement_int_width(int len, int i, int n);
void	ft_traitement_int_moin(int len, int i, int n);
void	ft_traitment_int_prec(int n, int len);
void	ft_traitement_int_zero(int len, int i, int n);
void	ft_traitement_null(int n);
void	ft_traitement_putstr_prec(char *str, int len);
void	ft_lol_lol(char *str, int len);
void	ft_trait_hexa_ma(unsigned long long nb);
void	ft_trait_hexa_m(unsigned long long nb);
void	ft_put16(unsigned long long nb, int m);
void	ft_puthexa_compt(unsigned long long h, int m);
void	ft_traitemt_hexa_zero(int len, int i, unsigned int n, int m);
void	ft_traitment_hexa_prec(unsigned int n, int len, int m);
int		ft_hexalen(unsigned int j);
void	ft_traitemt_hexa_moin(int len, int i, unsigned int n, int m);
int		ft_traitement_hexa(va_list list, int j, int m);
void	ft_traitement_hexa_width(int len, int i, unsigned int n, int m);
void	ft_traitement_hexa_null(unsigned int n, int m);
int		ft_put(int i);
int		ft_ifnega(int i, int n);
void	ft_someint(int len, int i, int n);
void	ft_somehexa(int len, int i, unsigned int n, int m);
void	ft_ifp(void);
void	ft_adresse_width(int len, int i, unsigned long long n, int m);
void	ft_adresse_null(unsigned long long n, int m);
void	ft_someadresse(int len, int i, unsigned long long n, int m);
void	ft_adresse_zero(int len, int i, unsigned long long n, int m);
void	ft_adresse_prec(unsigned long long n, int len, int m);
int		ft_adresselen(unsigned long long j);
void	ft_adresse_moin(int len, int i, unsigned long long n, int m);
int		ft_traitement_hexa(va_list list, int j, int m);
int		ft_adresse(va_list list, int j, int m);
int     ft_traitement_char(va_list list, int i);
char	*ft_strdup(const char *s);
void	ft_less_dot(void);

#endif
