/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:31:56 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 22:15:12 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFTPRINTF_H
#	define LIBFTPRINTF_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

void	ft_putnbr_fd(long long n, int fd);
void	ft_putnbr_base_fd(unsigned long long n, int fd, char *base);
size_t	ft_strlen(const char *mot);
int		ft_atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(char c);
/*
** libft
*/
/*
** Printf.c
*/
void	ft_width(va_list ap, const char *str, int *tab);
void	ft_precision(va_list ap, const char *str, int *tab);
void	string_process(va_list ap, const char *fmt, int *tab);
int		ft_printf(const char *fmt, ...);
void	flag_process(va_list ap, const char *fmt, int *tab);
/*
** Printf2.c
*/
int		is_managed(const char *str, int *tab);
void	ft_moins_ou_zero(const char *str, int *tab);
void	print_arg(va_list ap, const char *str, int *tab);
void	char_is_moins(int *tab);
void	arg_is_neg(int *tab, int i);
/*
** Parsing_int.c
*/
void	print_char(int taille, int *tab, char c);
int		calcul_taille(long long nombre, int base);
void	gest_precision(int taille, int *tab);
void	gest_width(int taille, int *tab, int i, int neg);
void	parsing_int(va_list ap, int *tab);
/*
**Parsing_string.c
*/
void	gest_width_str(int taille, int *tab, int i, int neg);
void	print_string(char *str, int *tab, int taille);
void	parsing_string(va_list ap, int *tab);
/*
**	Parsing_uint.c
*/
void	parsing_uint(va_list ap, int *tab);
void	init_tab(int *tab);
/*
** parsing_char.c
*/
void	gest_width_char(int taille, int *tab, int i);
void	gest_precision_char(int taille, int *tab);
void	parsing_char(va_list ap, int *tab);
/*
** parsing_hexa.c
*/
void	parsing_hexa(va_list ap, int *tab, int i);
/*
** Parsing_pointer.c
*/
int		calcul_taille_hexa(unsigned long long nombre, int base);
void	gest_width_pointer(int taille, int *tab, int i);
void	parsing_pointer(va_list ap, int *tab);
void	write_str(int *tab, const char *str);
/*
** parsing_percent.c
*/
void	gest_width_percent(int taille, int *tab, int i);
void	parsing_percent(int *tab);
#	endif
