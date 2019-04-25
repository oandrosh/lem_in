/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:55:31 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/25 16:55:34 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	addtype(int *flags)
{
	if (flags[3] == 1)
	{
		ft_joinchar('0', 1);
		flags[7]--;
		flags[6]--;
	}
}

static void	ft_m(unsigned long long int oct, int *flags, int size)
{
	addtype(flags);
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_base(oct, 8, 'x'));
	if (flags[6] > size && flags[6] > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - size));
		else
			ft_joinchar(' ', (flags[6] - flags[7]));
	}
}

static void	ft_nm(unsigned long long int oct, int *flags, int size)
{
	if (flags[3] == 1)
		flags[6]--;
	if (flags[4] == 1 && flags[7] < 0)
	{
		addtype(flags);
		if (flags[6] > size)
			ft_joinchar('0', (flags[6] - size));
		ft_joinstr(ft_itoa_base(oct, 8, 'x'));
	}
	else
	{
		if (flags[7] >= size && flags[3] == 1)
			flags[6]++;
		if (flags[6] > size && flags[6] > flags[7])
		{
			if (size > flags[7])
				ft_joinchar(' ', (flags[6] - size));
			else
				ft_joinchar(' ', (flags[6] - flags[7]));
		}
		addtype(flags);
		if (flags[7] > size)
			ft_joinchar('0', (flags[7] - size));
		ft_joinstr(ft_itoa_base(oct, 8, 'x'));
	}
}

void		ft_octal(unsigned long long int oct, int *flags)
{
	if (flags[7] == 0 && oct == 0)
	{
		if (flags[3] == 1)
			flags[6]--;
		if (flags[0] == 1)
			addtype(flags);
		if (flags[6] > 1)
			ft_joinchar(' ', flags[6]);
		if (flags[0] != 1)
			addtype(flags);
	}
	else if (flags[0] == 1)
		ft_m(oct, flags, ft_un_defsize(oct, 8));
	else
		ft_nm(oct, flags, ft_un_defsize(oct, 8));
}
