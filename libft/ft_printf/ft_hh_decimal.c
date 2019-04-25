/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hh_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:42:47 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/25 12:42:52 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_pm(char hh_dec, int *flags, int size)
{
	if (hh_dec < 0)
	{
		ft_joinchar('-', 1);
		hh_dec = hh_dec * -1;
	}
	else
		ft_joinchar('+', 1);
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_char(hh_dec, 10));
	if (flags[6] - 1 > size && flags[6] - 1 > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - 1 - size));
		else
			ft_joinchar(' ', (flags[6] - 1 - flags[7]));
	}
}

static void	ft_m(char hh_dec, int *flags, int size)
{
	if (hh_dec < 0)
		ft_joinchar('-', 1);
	else if (flags[2] == 1)
		ft_joinchar(' ', 1);
	else
		flags[6]++;
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_char(hh_dec, 10));
	if (flags[6] - 1 > size && flags[6] - 1 > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - 1 - size));
		else
			ft_joinchar(' ', (flags[6] - 1 - flags[7]));
	}
}

static void	ft_zer(char hh_dec, int *flags, int size)
{
	if (hh_dec < 0)
		ft_joinchar('-', 1);
	else if (flags[1] == 1)
		ft_joinchar('+', 1);
	else if (flags[2] == 1)
		ft_joinchar(' ', 1);
	else
		flags[6]++;
	if (flags[6] - 1 > size)
		ft_joinchar('0', (flags[6] - 1 - size));
	ft_joinstr(ft_itoa_char(hh_dec, 10));
}

static void	ft_nm(char hh_dec, int *flags, int size)
{
	if (hh_dec >= 0 && flags[1] != 1)
		flags[6]++;
	if (flags[6] - 1 > size && flags[6] - 1 > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - 1 - size));
		else
			ft_joinchar(' ', (flags[6] - 1 - flags[7]));
	}
	if (hh_dec < 0)
		ft_joinchar('-', 1);
	else if (flags[1] == 1)
		ft_joinchar('+', 1);
	else if (flags[2] == 1 && flags[6] - 1 <= flags[7])
		ft_joinchar(' ', 1);
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_char(hh_dec, 10));
}

void		ft_hh_decimal(char hh_dec, int *flags)
{
	if (flags[7] == 0 && hh_dec == 0)
	{
		if (flags[1] == 1)
			ft_joinchar('+', 1);
		else
			ft_joinchar(' ', 1);
		if (flags[6] > 1)
			ft_joinchar(' ', flags[6] - 1);
	}
	else if (flags[0] == 1)
	{
		if (flags[1] == 1)
			ft_pm(hh_dec, flags, ft_defsize_char(hh_dec, 10));
		else
			ft_m(hh_dec, flags, ft_defsize_char(hh_dec, 10));
	}
	else
	{
		if (flags[4] == 1 && flags[7] < 0)
			ft_zer(hh_dec, flags, ft_defsize_char(hh_dec, 10));
		else
			ft_nm(hh_dec, flags, ft_defsize_char(hh_dec, 10));
	}
}
