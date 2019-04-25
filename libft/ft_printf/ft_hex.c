/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:34:09 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/25 18:34:11 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	part2(int *flags, va_list ap, char type)
{
	unsigned long int		l_hex;
	unsigned long long int	ll_hex;
	unsigned int			i_hex;

	if (flags[5] == 3)
	{
		l_hex = va_arg(ap, unsigned long int);
		ft_hexal(l_hex, flags, type);
	}
	else if (flags[5] == 4)
	{
		ll_hex = va_arg(ap, unsigned long long int);
		ft_hexal(ll_hex, flags, type);
	}
	else if (flags[5] == -1)
	{
		i_hex = va_arg(ap, unsigned int);
		ft_hexal(i_hex, flags, type);
	}
}

void		ft_hex(int *flags, va_list ap, char type)
{
	unsigned short int		h_hex;
	unsigned char			hh_hex;

	if (flags[5] == 1)
	{
		h_hex = va_arg(ap, unsigned int);
		ft_hexal(h_hex, flags, type);
	}
	else if (flags[5] == 2)
	{
		hh_hex = va_arg(ap, unsigned int);
		ft_hh_hexal(hh_hex, flags, type);
	}
	else
		part2(flags, ap, type);
}
