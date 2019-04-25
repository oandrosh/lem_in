/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:59:14 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/28 15:59:17 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	addtype(void)
{
	ft_joinchar('0', 1);
	ft_joinchar('x', 1);
}

static void	ft_m(unsigned long long int ptr, int *flags, int size)
{
	addtype();
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_base(ptr, 16, 'x'));
	if (flags[6] > size && flags[6] > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - size));
		else
			ft_joinchar(' ', (flags[6] - flags[7]));
	}
}

static void	ft_nm(unsigned long long int ptr, int *flags, int size)
{
	if (flags[6] > size && flags[6] > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - size));
		else
			ft_joinchar(' ', (flags[6] - flags[7]));
	}
	addtype();
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_base(ptr, 16, 'x'));
}

void		ft_point(int *flags, va_list ap)
{
	unsigned long long ptr;

	if (!(ptr = va_arg(ap, unsigned long long int)))
		ptr = 0;
	flags[6] -= 2;
	if (flags[7] == 0 && ptr == 0)
	{
		if (flags[6] > 1)
			ft_joinchar(' ', flags[6]);
		addtype();
	}
	else if (flags[0] == 1)
		ft_m(ptr, flags, ft_un_defsize(ptr, 16));
	else
		ft_nm(ptr, flags, ft_un_defsize(ptr, 16));
}
