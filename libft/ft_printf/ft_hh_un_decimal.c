/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hh_un_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:31:33 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/25 13:31:34 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_m(unsigned char hh_un_decimal, int *flags, int size)
{
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_un_char(hh_un_decimal, 10, 'x'));
	if (flags[6] - 1 > size && flags[6] - 1 > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - 1 - size));
		else
			ft_joinchar(' ', (flags[6] - 1 - flags[7]));
	}
}

static void	ft_nm(unsigned char hh_un_decimal, int *flags, int size)
{
	if (flags[4] == 1 && flags[7] < 0)
	{
		if (flags[6] - 1 > size)
			ft_joinchar('0', (flags[6] - 1 - size));
		ft_joinstr(ft_itoa_un_char(hh_un_decimal, 10, 'x'));
	}
	else
	{
		flags[6]++;
		if (flags[6] - 1 > size && flags[6] - 1 > flags[7])
		{
			if (size > flags[7])
				ft_joinchar(' ', (flags[6] - 1 - size));
			else
				ft_joinchar(' ', (flags[6] - 1 - flags[7]));
		}
		if (flags[7] > size)
			ft_joinchar('0', (flags[7] - size));
		ft_joinstr(ft_itoa_un_char(hh_un_decimal, 10, 'x'));
	}
}

void		ft_hh_un_decimal(unsigned char hh_un_decimal, int *flags)
{
	if (flags[7] == 0 && hh_un_decimal == 0)
	{
		if (flags[6] > 1)
			ft_joinchar(' ', flags[6] - 1);
	}
	else if (flags[0] == 1)
		ft_m(hh_un_decimal, flags, ft_defsize_un_char(hh_un_decimal, 10));
	else
	{
		ft_nm(hh_un_decimal, flags, ft_defsize_un_char(hh_un_decimal, 10));
	}
}
