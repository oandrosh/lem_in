/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:35:14 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/24 15:35:18 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		clear(int *flags)
{
	int		i;

	i = 0;
	while (i != 8)
	{
		flags[i] = -1;
		i++;
	}
}

static int		mods(char a, int flag)
{
	if (a == 'h')
	{
		if (flag == 1)
			return (2);
		return (1);
	}
	if (a == 'l')
	{
		if (flag == 3)
			return (4);
		return (3);
	}
	if (a == 'L')
		return (5);
	return (-1);
}

static void		def_flags(char a, int *flags)
{
	if (a == '-')
		flags[0] = 1;
	else if (a == '+')
		flags[1] = 1;
	else if (a == ' ')
		flags[2] = 1;
	else if (a == '#')
		flags[3] = 1;
	else if (a == '0')
		flags[4] = 1;
}

static void		def_precision(char *str, int *flags)
{
	int i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
		flags[7] = ft_atoi(&str[i]);
	else
		flags[7] = 0;
}

void			ft_search_flags(char *str, int *flags)
{
	int		i;

	clear(flags);
	i = 0;
	while (ft_isflag(str[i]) == 1 && str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+' || str[i] == '#' ||
			str[i] == '0' || str[i] == ' ')
			def_flags(str[i], flags);
		else if (str[i] >= '0' && str[i] <= '9')
		{
			flags[6] = ft_atoi(&str[i]);
			while (str[i + 1] >= '0' && str[i + 1] <= '9')
				i++;
		}
		else if (str[i] == '.')
		{
			def_precision(&str[i + 1], flags);
			while (str[i + 1] >= '0' && str[i + 1] <= '9')
				i++;
		}
		else if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
			flags[5] = mods(str[i], flags[5]);
		i++;
	}
}
