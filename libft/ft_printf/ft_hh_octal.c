/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hh_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:16:02 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/25 18:16:05 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	addtype(int *flags)
{
	ft_joinchar('0', 1);
	flags[7]--;
	flags[6]--;
}

static void	ft_m(char hh_oct, int *flags, int size)
{
	if (flags[3] == 1)
		addtype(flags);
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_un_char(hh_oct, 8, 'x'));
	if (flags[6] > size && flags[6] > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - size));
		else
			ft_joinchar(' ', (flags[6] - flags[7]));
	}
}

static void	ft_nm(char hh_oct, int *flags, int size)
{
	if (flags[7] < 0 && flags[3] == 1)
		flags[6]--;
	if (flags[4] == 1 && flags[7] < 0)
	{
		if (flags[3] == 1)
			addtype(flags);
		if (flags[6] > size)
			ft_joinchar('0', (flags[6] - size));
		ft_joinstr(ft_itoa_un_char(hh_oct, 8, 'x'));
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
			addtype(flags);
		if (flags[7] > size)
			ft_joinchar('0', (flags[7] - size));
		ft_joinstr(ft_itoa_un_char(hh_oct, 8, 'x'));
	}
}

void		ft_hh_octal(char hh_oct, int *flags)
{
	if (flags[7] == 0 && hh_oct == 0)
	{
		if (flags[6] > 1)
			ft_joinchar(' ', flags[6] - 1);
	}
	else if (flags[0] == 1)
		ft_m(hh_oct, flags, ft_defsize_un_char(hh_oct, 8));
	else
	{
		ft_nm(hh_oct, flags, ft_defsize_un_char(hh_oct, 8));
	}
}
