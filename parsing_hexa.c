/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:17:57 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 19:53:47 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parsing_hexa(va_list ap, int *tab, int i)
{
	unsigned int	var;
	int				taille;

	var = va_arg(ap, unsigned int);
	if (tab[3] < 0)
		tab[3] = -1;
	taille = calcul_taille_hexa((unsigned long long)var, 16);
	if ((tab[3] == 0 && !var))
		taille--;
	gest_width(taille, tab, 0, 0);
	gest_precision(taille, tab);
	if (!(tab[3] == 0 && !var))
	{
		if (i == 0)
			ft_putnbr_base_fd((unsigned long long)var, 1, "0123456789abcdef");
		else
			ft_putnbr_base_fd((unsigned long long)var, 1, "0123456789ABCDEF");
	}
	tab[5] += taille;
	gest_width(taille, tab, 1, 0);
}
/*
** i = 0 -> base hexa mini
** i = 1 -> base hexa MAJ
*/
