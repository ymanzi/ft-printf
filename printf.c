/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 07:37:17 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/27 20:28:51 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_width(va_list ap, const char *str, int *tab)
{
	if (str[tab[4]] == '-' || str[tab[4]] == '*' || ft_isdigit(str[tab[4]]))
	{
		if (str[tab[4]] == '-')
			char_is_moins(tab);
		else if (ft_isdigit(str[tab[4]]))
		{
			tab[2] = ft_atoi(str + tab[4]);
			while (ft_isdigit(str[tab[4]]))
				tab[4]++;
		}
		else if (str[tab[4]] == '*')
		{
			tab[2] = va_arg(ap, int);
			if (tab[2] < 0)
				arg_is_neg(tab, 2);
			tab[4]++;
		}
	}
}

/*
** tableau de int
** [0] moins
** [1] zero
** [2] width
** [3] precision
** [4] i
** [5] nbr print
** [6] verif precision activation de flag, voir parsing_string
** [7] si un argument a ete trouve, si non print la string en brut
*/

void	ft_precision(va_list ap, const char *str, int *tab)
{
	if (str[tab[4]] == '.')
	{
		tab[3] = 0;
		tab[4]++;
	}
	if (str[tab[4]] == '*')
	{
		tab[3] = va_arg(ap, int);
		if (tab[3] < 0)
			tab[6] = 1;
		else
			tab[6] = -1;
		tab[4]++;
	}
	else if (ft_isdigit(str[tab[4]]))
	{
		tab[3] = ft_atoi(str + tab[4]);
		if (tab[3] < 0)
			tab[3] = 0;
		else
			tab[6] = -1;
		while (ft_isdigit(str[tab[4]]))
			tab[4]++;
	}
}

/*
** tableau de int
** [0] moins
** [1] zero
** [2] width
** [3] precision
** [4] i
** [5] nbr print
** [6] verif precision activation de flag, voir parsing_string
** [7] si un argument a ete trouve, si non print la string en brut
**
** Voir init_tab dans parsing_uint.c
*/

void	flag_process(va_list ap, const char *fmt, int *tab)
{
	init_tab(tab);
	tab[4]++;
	ft_moins_ou_zero(fmt, tab);
	while (fmt[tab[4]] == '-' || fmt[tab[4]] == '*'
			|| ft_isdigit(fmt[tab[4]]) || fmt[tab[4]] == '.')
	{
		if (fmt[tab[4]] == '.')
			ft_precision(ap, fmt, tab);
		else if (fmt[tab[4]] == '0')
		{
			tab[1] = 1;
			tab[4]++;
		}
		else
			ft_width(ap, fmt, tab);
	}
	print_arg(ap, fmt, tab);
}

void	string_process(va_list ap, const char *fmt, int *tab)
{
	if (fmt[tab[4]] == '%')
	{
		if (tab[4] + 1 < (int)ft_strlen(fmt) && is_managed(fmt, tab))
			flag_process(ap, fmt, tab);
		else if (tab[4] + 1 < (int)ft_strlen(fmt) && fmt[tab[4] + 1] == ' ')
		{
			write(1, "%", 1);
			tab[5]++;
			tab[4]++;
		}
	}
	else
	{
		write(1, &fmt[tab[4]], 1);
		tab[5]++;
	}
	tab[4]++;
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		tab[7];

	i = 0;
	while (i < 7)
		tab[i++] = -1;
	tab[4] = 0;
	tab[5] = 0;
	va_start(ap, fmt);
	while (fmt[tab[4]])
		string_process(ap, fmt, tab);
	va_end(ap);
	return (tab[5]);
}
