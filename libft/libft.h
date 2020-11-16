/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:33:03 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 20:45:37 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *mot);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(long long n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_base_fd(unsigned long long n, int fd, char *base);

#	endif
