/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:51:56 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/26 12:51:59 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	addtype(int *flags, char type, unsigned long long int hex)
{
	if (flags[3] == 1 && hex != 0)
	{
		ft_joinchar('0', 1);
		ft_joinchar(type, 1);
		flags[6] -= 2;
	}
}

static void	ft_m(unsigned long long int hex, int *flags, int size, char type)
{
	addtype(flags, type, hex);
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_base(hex, 16, type));
	if (flags[6] > size && flags[6] > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - size));
		else
			ft_joinchar(' ', (flags[6] - flags[7]));
	}
}

static void	ft_nm(unsigned long long int hex, int *flags, int size, char type)
{
	if (flags[4] == 1 && flags[7] < 0)
	{
		addtype(flags, type, hex);
		if (flags[6] > size)
			ft_joinchar('0', (flags[6] - size));
		ft_joinstr(ft_itoa_base(hex, 16, type));
	}
	else
	{
		if (flags[3] == 1 && hex != 0)
			flags[6] -= 2;
		if (flags[6] > size && flags[6] > flags[7])
		{
			if (size > flags[7])
				ft_joinchar(' ', (flags[6] - size));
			else
				ft_joinchar(' ', (flags[6] - flags[7]));
		}
		addtype(flags, type, hex);
		if (flags[7] > size)
			ft_joinchar('0', (flags[7] - size));
		ft_joinstr(ft_itoa_base(hex, 16, type));
	}
}

void		ft_hexal(unsigned long long int hex, int *flags, char type)
{
	if (flags[7] == 0 && hex == 0)
	{
		if (flags[6] > 1)
			ft_joinchar(' ', flags[6]);
	}
	else if (flags[0] == 1)
		ft_m(hex, flags, ft_un_defsize(hex, 16), type);
	else
		ft_nm(hex, flags, ft_un_defsize(hex, 16), type);
}
