/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:21:24 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 20:24:40 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_tab(int *tab)
{
	int i;

	i = 0;
	while (i < 4)
		tab[i++] = -1;
	tab[2] = 0;
	tab[6] = 0;
}

void	parsing_uint(va_list ap, int *tab)
{
	unsigned long	var;
	int				taille;

	var = va_arg(ap, unsigned int);
	if (tab[3] < 0)
		tab[3] = -1;
	taille = calcul_taille((long long)var, 10);
	if (tab[3] == 0 && !var)
		taille--;
	gest_width(taille, tab, 0, 0);
	gest_precision(taille, tab);
	if (!(tab[3] == 0 && !var))
		ft_putnbr_fd((unsigned long long)var, 1);
	tab[5] += taille;
	gest_width(taille, tab, 1, 0);
}
