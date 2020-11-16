/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:49:35 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 19:51:20 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	gest_width_char(int taille, int *tab, int i)
{
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

void	gest_precision_char(int taille, int *tab)
{
	int	nbr_elem;

	nbr_elem = tab[3] - tab[2] - taille;
	print_char(nbr_elem, tab, ' ');
}

void	parsing_char(va_list ap, int *tab)
{
	char	c;
	int		taille;

	c = va_arg(ap, int);
	if (tab[3] < 0)
		tab[3] = -1;
	taille = 1;
	gest_width_char(taille, tab, 0);
	write(1, &c, 1);
	tab[5]++;
	gest_width_char(taille, tab, 1);
}
