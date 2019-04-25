/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:38:43 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/23 07:37:51 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_pm(long long int decimal, int *flags, int size)
{
	if (decimal < 0)
	{
		ft_joinchar('-', 1);
		decimal = decimal * -1;
	}
	else
		ft_joinchar('+', 1);
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_long(decimal));
	if (flags[6] - 1 > size && flags[6] - 1 > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - 1 - size));
		else
			ft_joinchar(' ', (flags[6] - 1 - flags[7]));
	}
}

static void	ft_m(long long int decimal, int *flags, int size)
{
	if (decimal < 0)
	{
		ft_joinchar('-', 1);
		decimal = decimal * -1;
	}
	else if (flags[2] == 1)
		ft_joinchar(' ', 1);
	else
		flags[6]++;
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_long(decimal));
	if (flags[6] - 1 > size && flags[6] - 1 > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - 1 - size));
		else
			ft_joinchar(' ', (flags[6] - 1 - flags[7]));
	}
}

static void	ft_zer(long long int decimal, int *flags, int size)
{
	if (decimal < 0)
	{
		ft_joinchar('-', 1);
		decimal = decimal * -1;
	}
	else if (flags[1] == 1)
		ft_joinchar('+', 1);
	else if (flags[2] == 1)
		ft_joinchar(' ', 1);
	else
		flags[6]++;
	if (flags[6] - 1 > size)
		ft_joinchar('0', (flags[6] - 1 - size));
	ft_joinstr(ft_itoa_long(decimal));
}

static void	ft_nm(long long int decimal, int *flags, int size)
{
	if (decimal >= 0 && flags[1] != 1)
		flags[6]++;
	if (flags[6] - 1 > size && flags[6] - 1 > flags[7])
	{
		if (size > flags[7])
			ft_joinchar(' ', (flags[6] - 1 - size));
		else
			ft_joinchar(' ', (flags[6] - 1 - flags[7]));
	}
	if (decimal < 0)
	{
		ft_joinchar('-', 1);
		decimal = decimal * -1;
	}
	else if (flags[1] == 1)
		ft_joinchar('+', 1);
	else if (flags[2] == 1 && flags[6] - 1 <= flags[7])
		ft_joinchar(' ', 1);
	if (flags[7] > size)
		ft_joinchar('0', (flags[7] - size));
	ft_joinstr(ft_itoa_long(decimal));
}

void		ft_decimal(long long int decimal, int *flags)
{
	if (flags[7] == 0 && decimal == 0)
	{
		if (flags[1] == 1)
			ft_joinchar('+', 1);
		else if (flags[2] == 1)
			ft_joinchar(' ', 1);
		if (flags[6] > 1)
			ft_joinchar(' ', flags[6]);
	}
	else if (flags[0] == 1)
	{
		if (flags[1] == 1)
			ft_pm(decimal, flags, ft_defsize(decimal, 10));
		else
			ft_m(decimal, flags, ft_defsize(decimal, 10));
	}
	else
	{
		if (flags[4] == 1 && flags[7] < 0)
			ft_zer(decimal, flags, ft_defsize(decimal, 10));
		else
			ft_nm(decimal, flags, ft_defsize(decimal, 10));
	}
}
