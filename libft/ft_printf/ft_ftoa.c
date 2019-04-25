/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:32:23 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/29 11:32:25 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long double	rounding(long double ldb, int precision)
{
	int			i;
	long double	add;

	i = 0;
	add = 0.5;
	while (++i <= precision)
		add *= 0.1;
	ldb += add;
	return (ldb);
}

static void			add_mant(long double mant, int precision, char *res,
	int index)
{
	int		i;

	if (precision > 0)
	{
		res[index++] = '.';
		while (precision > 0)
		{
			mant *= 10;
			i = (int)mant;
			res[index] = i + '0';
			mant = mant - i;
			precision--;
			index++;
		}
	}
}

static void			add_ldb(long double ldb, char *res, int length,
	int precision)
{
	int	index;
	int	i;

	index = 0;
	while (length > 0)
	{
		ldb *= 10;
		i = (int)ldb;
		res[index] = i + '0';
		ldb = ldb - i;
		length--;
		index++;
	}
	add_mant(ldb, precision, res, index);
}

char				*ft_ftoa(long double ldb, int precision)
{
	char		*res;
	int			index;
	int			length;

	index = 0;
	length = 0;
	ldb = rounding(ldb, precision);
	while (ldb >= 1)
	{
		ldb = ldb / 10;
		length++;
	}
	if (precision > 0)
		res = ft_memalloc(precision + length + 2);
	else
		res = ft_memalloc(length + 1);
	if (length == 0)
	{
		res[index++] = '0';
		add_mant(ldb, precision, res, index);
	}
	else
		add_ldb(ldb, res, length, precision);
	return (res);
}
