/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:27:41 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/25 13:27:47 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		second_part(int *flags, va_list ap)
{
	unsigned long int		l_un_dec;
	unsigned long long int	ll_un_dec;
	unsigned int			i_un_dec;

	if (flags[5] == 3)
	{
		l_un_dec = va_arg(ap, unsigned long int);
		ft_un_decimal(l_un_dec, flags);
	}
	else if (flags[5] == 4)
	{
		ll_un_dec = va_arg(ap, unsigned long long int);
		ft_un_decimal(ll_un_dec, flags);
	}
	else if (flags[5] == -1)
	{
		i_un_dec = va_arg(ap, unsigned int);
		ft_un_decimal(i_un_dec, flags);
	}
}

void			ft_un_dec(int *flags, va_list ap)
{
	unsigned short int		h_un_dec;
	unsigned char			hh_un_dec;

	if (flags[5] == 1)
	{
		h_un_dec = va_arg(ap, unsigned int);
		ft_un_decimal(h_un_dec, flags);
	}
	else if (flags[5] == 2)
	{
		hh_un_dec = va_arg(ap, unsigned int);
		ft_hh_un_decimal(hh_un_dec, flags);
	}
	else
		second_part(flags, ap);
}
