/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:31:20 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/25 13:31:23 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_m(unsigned long long int un_decimal, int *flags, int size)
{
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_base(un_decimal, 10, 'x'));
	if (flags[6] > size && flags[6] > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - size));
		else
			ft_joinchar(' ', (flags[6] - flags[7]));
	}
}

static void	ft_nm(unsigned long long int un_decimal, int *flags, int size)
{
	if (flags[4] == 1 && flags[7] < 0)
	{
		if (flags[6] > size)
			ft_joinchar('0', (flags[6] - size));
		ft_joinstr(ft_itoa_base(un_decimal, 10, 'x'));
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
		if (flags[7] > size)
			ft_joinchar('0', (flags[7] - size));
		ft_joinstr(ft_itoa_base(un_decimal, 10, 'x'));
	}
}

void		ft_un_decimal(unsigned long long int un_decimal, int *flags)
{
	if (flags[7] == 0 && un_decimal == 0)
	{
		if (flags[6] > 1)
			ft_joinchar(' ', flags[6]);
	}
	else if (flags[0] == 1)
		ft_m(un_decimal, flags, ft_un_defsize(un_decimal, 10));
	else
		ft_nm(un_decimal, flags, ft_un_defsize(un_decimal, 10));
}
