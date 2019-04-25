/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:06:01 by oandrosh          #+#    #+#             */
/*   Updated: 2019/02/07 11:37:53 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_isflag(char a)
{
	if (a == '-' || a == '+' || a == '#' || a == '0' || a == ' ' || a == '.' ||
		a == 'l' || a == 'L' || a == 'h')
		return (1);
	else if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}

int			ft_isconversion(char a)
{
	if (a == 'i' || a == 'd' || a == 'u' || a == 'o' || a == 'x' || a == 'X' ||
			a == 'c' || a == 's' || a == 'p' || a == 'f')
		return (1);
	else
		return (0);
}

static void	deftype(char c, int *flags, va_list ap)
{
	char	a;

	if (c == 'i' || c == 'd')
		ft_dec(flags, ap);
	if (c == 'u')
		ft_un_dec(flags, ap);
	if (c == 'o')
		ft_oct(flags, ap);
	if (c == 'x' || c == 'X')
		ft_hex(flags, ap, c);
	if (c == 'c')
	{
		a = va_arg(ap, int);
		ft_char(flags, a);
	}
	if (c == 's')
		ft_string(flags, ap);
	if (c == 'p')
		ft_point(flags, ap);
	if (c == 'f')
		ft_float(flags, ap);
}

int			ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		flags[8];

	g_count = 0;
	va_start(ap, str);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_search_flags(&str[++i], flags);
			while (ft_isflag(str[i]) == 1)
				i++;
			if (ft_isconversion(str[i]) == 1)
				deftype(str[i], flags, ap);
			else if (str[i] != '\0')
				ft_char(flags, str[i]);
		}
		else
			ft_joinchar(str[i], 1);
	}
	va_end(ap);
	return (g_count);
}
