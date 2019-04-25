/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:44:13 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/25 12:49:43 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_defsize(long long int i, int base)
{
	int	size;

	size = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i = i / base;
		size++;
	}
	return (size);
}

int		ft_defsize_char(char a, int base)
{
	int size;

	size = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a = a / base;
		size++;
	}
	return (size);
}

int		ft_un_defsize(unsigned long long int i, int base)
{
	int size;

	size = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i = i / base;
		size++;
	}
	return (size);
}

int		ft_defsize_un_char(unsigned char a, int base)
{
	int size;

	size = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a = a / base;
		size++;
	}
	return (size);
}

int		ft_defsize_float(long double ldb, int precision)
{
	int length;

	length = 0;
	while (ldb > 1)
	{
		ldb = ldb / 10;
		length++;
	}
	if (length == 0)
		length++;
	if (precision > 0)
		length++;
	return (length + precision);
}
