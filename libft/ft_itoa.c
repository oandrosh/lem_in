/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 06:08:35 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/30 10:40:08 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*min(int n)
{
	int		i;
	int		x;
	char	*res;

	i = 1;
	x = n;
	while (x <= -1)
	{
		x = x / 10;
		i++;
	}
	res = (char*)malloc(i + 1);
	if (res == 0)
		return (NULL);
	res[i] = '\0';
	while (i > 1)
	{
		i--;
		res[i] = (n % 10 * -1) + '0';
		n = n / 10;
	}
	res[0] = '-';
	return (res);
}

static char	*plu(int n)
{
	int		i;
	int		x;
	char	*res;

	i = 0;
	x = n;
	if (n == 0)
		i++;
	while (x > 0)
	{
		x = x / 10;
		i++;
	}
	res = (char*)malloc(i + 1);
	if (res == 0)
		return (NULL);
	res[i] = '\0';
	while (i > 0)
	{
		i--;
		res[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	if (n < 0)
		return (min(n));
	else if (n >= 0)
		return (plu(n));
	else
		return (0);
}
