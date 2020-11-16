/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:07:14 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 22:21:36 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		calcul_taille_hexa(unsigned long long nombre, int base)
{
	int	i;

	i = 1;
	while (nombre > (unsigned long long)base - 1)
	{
		i++;
		nombre /= base;
	}
	return (i);
}

void	gest_width_pointer(int taille, int *tab, int i)
{
	if (taille - 2 < tab[3])
		taille = tab[3] + 2;
	if (i == 0 && tab[0] == -1)
	{
		if (tab[1] == 1 && tab[2] > tab[3] && tab[3] < 0)
			print_char(tab[2] - taille, tab, '0');
		else
			print_char(tab[2] - taille, tab, ' ');
	}
	if (i == 1 && tab[0] == 1)
		print_char(tab[2] - taille, tab, ' ');
}

void	write_str(int *tab, const char *str)
{
	write(1, str, ft_strlen(str));
	tab[5] += ft_strlen(str);
}

void	parsing_pointer(va_list ap, int *tab)
{
	unsigned long	var;
	int				taille;

	var = va_arg(ap, unsigned long);
	if (tab[3] < 0)
		tab[3] = -1;
	taille = calcul_taille_hexa((unsigned long long)var, 16);
	if (taille > 16)
		taille = 16;
	if ((tab[3] == 0 && !var))
		taille--;
	if (tab[0] == -1 && tab[1] == 1)
		write_str(tab, "0x");
	gest_width_pointer(taille + 2, tab, 0);
	if (!(tab[0] == -1 && tab[1] == 1))
		write_str(tab, "0x");
	gest_precision(taille, tab);
	if (!(tab[3] == 0 && !var))
		ft_putnbr_base_fd((unsigned long long)var, 1, "0123456789abcdef");
	tab[5] += taille;
	gest_width_pointer(taille + 2, tab, 1);
}
