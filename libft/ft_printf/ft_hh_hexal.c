/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hh_hexal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:45:09 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/26 14:45:12 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	addtype(int *flags, char type)
{
	ft_joinchar('0', 1);
	ft_joinchar(type, 1);
	flags[6] -= 2;
}

static void	ft_m(char hh_hex, int *flags, int size, char type)
{
	if (flags[3] == 1)
		addtype(flags, type);
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_un_char(hh_hex, 16, type));
	if (flags[6] > size && flags[6] > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - size));
		else
			ft_joinchar(' ', (flags[6] - flags[7]));
	}
}

static void	ft_nm(char hh_hex, int *flags, int size, char type)
{
	if (flags[3] == 1)
		flags[6] -= 2;
	if (flags[4] == 1 && flags[7] < 0)
	{
		if (flags[3] == 1)
			addtype(flags, type);
		if (flags[6] > size)
			ft_joinchar('0', (flags[6] - size));
		ft_joinstr(ft_itoa_un_char(hh_hex, 16, type));
	}
	else
	{
		if (flags[6] > size && flags[6] > flags[7])
		{
			if (size > flags[7])
				ft_joinchar(' ', (flags[6] - size));
			else
				ft_joinchar(' ', (flags[6] - flags[7]));
		}
		if (flags[3] == 1)
			addtype(flags, type);
		if (flags[7] > size)
			ft_joinchar('0', (flags[7] - size));
		ft_joinstr(ft_itoa_un_char(hh_hex, 16, type));
	}
}

void		ft_hh_hexal(char hh_hex, int *flags, char type)
{
	if (flags[7] == 0 && hh_hex == 0)
	{
		if (flags[6] > 1)
			ft_joinchar(' ', flags[6] - 1);
	}
	else if (flags[0] == 1)
		ft_m(hh_hex, flags, ft_defsize_un_char(hh_hex, 16), type);
	else
	{
		ft_nm(hh_hex, flags, ft_defsize_un_char(hh_hex, 16), type);
	}
}
