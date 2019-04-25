/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:13:11 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/23 05:35:40 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		part2(int *flags, va_list ap)
{
	long int		l_dec;
	long long int	ll_dec;
	int				i_dec;

	if (flags[5] == 3)
	{
		l_dec = va_arg(ap, long int);
		ft_decimal(l_dec, flags);
	}
	if (flags[5] == 4)
	{
		ll_dec = va_arg(ap, long long int);
		ft_decimal(ll_dec, flags);
	}
	if (flags[5] == -1)
	{
		i_dec = va_arg(ap, int);
		ft_decimal(i_dec, flags);
	}
}

void			ft_dec(int *flags, va_list ap)
{
	short int		h_dec;
	char			hh_dec;

	if (flags[5] == 1)
	{
		h_dec = va_arg(ap, int);
		ft_decimal(h_dec, flags);
	}
	else if (flags[5] == 2)
	{
		hh_dec = va_arg(ap, int);
		ft_hh_decimal(hh_dec, flags);
	}
	else
		part2(flags, ap);
}
