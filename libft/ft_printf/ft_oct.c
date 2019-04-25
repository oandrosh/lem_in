/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:46:10 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/25 16:46:12 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	part2(int *flags, va_list ap)
{
	unsigned long int		l_oct;
	unsigned long long int	ll_oct;
	unsigned int			i_oct;

	if (flags[5] == 3)
	{
		l_oct = va_arg(ap, unsigned long int);
		ft_octal(l_oct, flags);
	}
	else if (flags[5] == 4)
	{
		ll_oct = va_arg(ap, unsigned long long int);
		ft_octal(ll_oct, flags);
	}
	else if (flags[5] == -1)
	{
		i_oct = va_arg(ap, unsigned int);
		ft_octal(i_oct, flags);
	}
}

void		ft_oct(int *flags, va_list ap)
{
	unsigned short int		h_oct;
	unsigned char			hh_oct;

	if (flags[5] == 1)
	{
		h_oct = va_arg(ap, unsigned int);
		ft_octal(h_oct, flags);
	}
	else if (flags[5] == 2)
	{
		hh_oct = va_arg(ap, unsigned int);
		ft_hh_octal(hh_oct, flags);
	}
	else
		part2(flags, ap);
}
