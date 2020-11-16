/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:47:00 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 19:54:29 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	gest_width_percent(int taille, int *tab, int i)
{
	if (i == 0 && tab[0] == -1)
	{
		if (tab[1] == 1 && tab[2] > 0)
			print_char(tab[2] - taille, tab, '0');
		else
			print_char(tab[2] - taille, tab, ' ');
	}
	if (i == 1 && tab[0] == 1)
		print_char(tab[2] - taille, tab, ' ');
}

void	parsing_percent(int *tab)
{
	int	taille;

	taille = 1;
	if (tab[3] < 0)
		tab[3] = -1;
	gest_width_percent(taille, tab, 0);
	write(1, "%", 1);
	tab[5]++;
	gest_width_percent(taille, tab, 1);
}
