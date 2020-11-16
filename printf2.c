/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:16:53 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 20:21:27 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_managed(const char *str, int *tab)
{
	char c;

	c = str[tab[4] + 1];
	return (c == '-' || c == '0' || c == '.' || c == '*' || c == 'c'
			|| c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%' || ft_isdigit(c));
}

void	ft_moins_ou_zero(const char *str, int *tab)
{
	if (str[tab[4]] == '-')
		char_is_moins(tab);
	else if (str[tab[4]] == '0')
	{
		tab[1] = 1;
		tab[4]++;
	}
	else
	{
		tab[1] = -1;
		tab[0] = -1;
	}
}

void	print_arg(va_list ap, const char *str, int *tab)
{
	if (str[tab[4]] == 's')
		parsing_string(ap, tab);
	else if (str[tab[4]] == 'd')
		parsing_int(ap, tab);
	else if (str[tab[4]] == 'i')
		parsing_int(ap, tab);
	else if (str[tab[4]] == 'c')
		parsing_char(ap, tab);
	else if (str[tab[4]] == 'p')
		parsing_pointer(ap, tab);
	else if (str[tab[4]] == 'x')
		parsing_hexa(ap, tab, 0);
	else if (str[tab[4]] == 'X')
		parsing_hexa(ap, tab, 1);
	else if (str[tab[4]] == 'u')
		parsing_uint(ap, tab);
	else if (str[tab[4]] == '%')
		parsing_percent(tab);
	else
		tab[4]--;
}

void	char_is_moins(int *tab)
{
	tab[0] = 1;
	tab[4]++;
}

void	arg_is_neg(int *tab, int i)
{
	tab[0] = 1;
	tab[i] *= -1;
}
