/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:09:49 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/23 05:24:18 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_itoa_base(unsigned long long int i, int base, char type)
{
	char	*res;
	int		size;
	int		index;
	char	*line;

	if (type == 'x')
		line = ft_strdup("0123456789abcdef");
	else
		line = ft_strdup("0123456789ABCDEF");
	size = ft_un_defsize(i, base);
	if ((res = (char*)malloc(size + 1)))
	{
		res[size] = '\0';
		while (--size >= 0)
		{
			index = i % base;
			res[size] = line[index];
			i = i / base;
		}
	}
	ft_strdel(&line);
	return (res);
}
