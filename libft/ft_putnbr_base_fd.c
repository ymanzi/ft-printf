/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:45:40 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 20:22:33 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	affiche(unsigned long long n, int fd, char *s)
{
	if (n > 15)
	{
		affiche((n / 16), fd, s);
		affiche((n % 16), fd, s);
	}
	else
		ft_putchar_fd(s[n], fd);
}

void		ft_putnbr_base_fd(unsigned long long n, int fd, char *base)
{
	affiche(n, fd, base);
}
