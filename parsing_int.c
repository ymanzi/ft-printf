/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:27:00 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 22:13:41 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_char(int taille, int *tab, char c)
{
	int a;

	a = tab[0];
	while (taille-- > 0)
	{
		write(1, &c, 1);
		tab[5]++;
	}
}

int		calcul_taille(long long nombre, int base)
{
	int i;

	i = 1;
	if (nombre < 0)
	{
		nombre *= -1;
		i++;
	}
	while (nombre > base - 1)
	{
		i++;
		nombre /= base;
	}
	return (i);
}

void	gest_precision(int taille, int *tab)
{
	int nbr_elem;

	nbr_elem = tab[3] - taille;
	print_char(nbr_elem, tab, '0');
}

void	gest_width(int taille, int *tab, int i, int neg)
{
	if (taille < tab[3])
		taille = tab[3];
	if (i == 0 && tab[0] == -1)
	{
		if (tab[1] == 1 && tab[2] > tab[3] && tab[3] < 0)
			print_char(tab[2] - taille - neg, tab, '0');
		else
			print_char(tab[2] - taille - neg, tab, ' ');
	}
	if (i == 1 && tab[0] == 1)
		print_char(tab[2] - taille - neg, tab, ' ');
}

void	parsing_int(va_list ap, int *tab)
{
	long	var;
	int		neg;
	int		taille;

	var = va_arg(ap, int);
	if (tab[3] < 0)
		tab[3] = -1;
	neg = (var < 0 ? 1 : 0);
	if (neg)
		var *= -1;
	taille = calcul_taille((long long)var, 10);
	if ((tab[3] == 0 && !var))
		taille--;
	if (neg && tab[0] != 1 && tab[1] == 1 && tab[2] > tab[3] && tab[3] < 0)
		write_str(tab, "-");
	gest_width(taille, tab, 0, neg);
	if (neg && !(tab[0] != 1 && tab[1] == 1 && tab[2] > tab[3] && tab[3] < 0))
		write_str(tab, "-");
	gest_precision(taille, tab);
	if (!(tab[3] == 0 && !var))
		ft_putnbr_fd((unsigned long long)var, 1);
	tab[5] += taille;
	gest_width(taille, tab, 1, neg);
}
