/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:09:42 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/23 05:15:37 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*min(long long int i, int size)
{
	char *res;

	if (i < -9223372036854775807)
		res = ft_strdup("9223372036854775808");
	else if ((res = (char*)malloc(sizeof(char) * (size + 1))))
	{
		i = i * -1;
		res[size] = '\0';
		while (--size > 0)
		{
			res[size] = i % 10 + '0';
			i = i / 10;
		}
	}
	return (res);
}

char			*ft_itoa_long(long long int i)
{
	char	*res;
	int		size;

	size = ft_defsize(i, 10);
	if (i < 0)
		res = min(i, size);
	else if ((res = (char*)malloc(size + 1)))
	{
		res[size] = '\0';
		while (--size >= 0)
		{
			res[size] = i % 10 + '0';
			i = i / 10;
		}
	}
	return (res);
}

char			*ft_itoa_char(char a, int base)
{
	char	*res;
	int		size;

	if (a == -128)
		return (ft_strdup("128"));
	if (a < 0)
		a = a * -1;
	size = ft_defsize_char(a, base);
	res = (char*)malloc(size + 1);
	res[size] = '\0';
	while (--size >= 0)
	{
		if (a == 0)
			res[size] = '0';
		res[size] = a % base + '0';
		a = a / base;
	}
	return (res);
}

char			*ft_itoa_un_char(unsigned char a, int base, char type)
{
	char	*res;
	int		size;
	int		index;
	char	*line;

	line = (char*)malloc(17);
	if (type == 'x')
		line = "0123456789abcdef";
	else
		line = "0123456789ABCDEF";
	size = ft_defsize_un_char(a, base);
	res = (char*)malloc(size + 1);
	res[size] = '\0';
	while (--size >= 0)
	{
		index = a % base;
		res[size] = line[index];
		a = a / base;
	}
	return (res);
}
