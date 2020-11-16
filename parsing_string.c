/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:11:08 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 19:56:28 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	gest_width_str(int taille, int *tab, int i, int neg)
{
	if (i == 0 && tab[0] == -1)
	{
		if (tab[1] == 1 && (tab[3] > taille || tab[2] > taille))
			print_char(tab[2] - taille - neg, tab, '0');
		else
			print_char(tab[2] - taille - neg, tab, ' ');
	}
	else if (i == 1 && tab[0] != -1)
		print_char(tab[2] - taille - neg, tab, ' ');
}

void	print_string(char *str, int *tab, int taille)
{
	int	i;

	i = 0;
	if (tab[3] == -1 && tab[6] == -1)
		while (i < taille && str[i])
		{
			write(1, &str[i++], 1);
			tab[5]++;
		}
	else
		while (i < taille && str[i])
		{
			write(1, &str[i++], 1);
			tab[5]++;
		}
}

void	parsing_string(va_list ap, int *tab)
{
	char	*str;
	int		taille;

	str = va_arg(ap, char*);
	if (!str)
		str = "(null)";
	taille = ft_strlen(str);
	if (tab[3] < 0 && tab[6] == 1)
		tab[3] *= -1;
	if (taille > tab[3] && tab[3] > 0 && tab[6] != 1)
		taille = tab[3];
	else if (tab[3] == 0)
		taille = 0;
	gest_width_str(taille, tab, 0, 0);
	print_string(str, tab, taille);
	gest_width_str(taille, tab, 1, 0);
}
