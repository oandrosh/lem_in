/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:55:20 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/28 18:23:07 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		minus(long double ldb, int *flags, int size)
{
	if (ldb < 0)
	{
		ft_joinchar('-', 1);
		ldb *= -1;
	}
	else if (flags[1] == 1)
		ft_joinchar('+', 1);
	else if (flags[2] == 1)
		ft_joinchar(' ', 1);
	else
		flags[6]++;
	ft_joinstr(ft_ftoa(ldb, flags[7]));
	if (flags[3] == 1 && flags[7] == 0)
		ft_joinchar('.', 1);
	if (--flags[6] > size)
		ft_joinchar(' ', (flags[6] - size));
}

static void		not_minus(long double ldb, int *flags, int size)
{
	if (flags[1] == 1 || flags[2] == 1 || ldb < 0)
		flags[6]--;
	if (size < flags[6] && flags[4] != 1)
		ft_joinchar(' ', (flags[6] - size));
	if (ldb < 0)
	{
		ft_joinchar('-', 1);
		ldb *= -1;
	}
	else if (flags[1] == 1)
		ft_joinchar('+', 1);
	else if (flags[2] == 1)
		ft_joinchar(' ', 1);
	if (size < flags[6] && flags[4] == 1)
		ft_joinchar('0', (flags[6] - size));
	ft_joinstr(ft_ftoa(ldb, flags[7]));
	if (flags[3] == 1 && flags[7] == 0)
		ft_joinchar('.', 1);
}

static void		add_flags(long double ldb, int *flags)
{
	int	length;

	length = ft_defsize_float(ldb, flags[7]);
	if (flags[0] == 1)
		minus(ldb, flags, length);
	else
		not_minus(ldb, flags, length);
}

void			ft_float(int *flags, va_list ap)
{
	long double		flt;

	if (flags[7] < 0)
		flags[7] = 6;
	if (flags[7] == 0 && flags[3] == 1)
		flags[6]--;
	if (flags[5] == 5)
	{
		flt = va_arg(ap, long double);
		add_flags(flt, flags);
	}
	else
	{
		flt = va_arg(ap, double);
		add_flags(flt, flags);
	}
}
