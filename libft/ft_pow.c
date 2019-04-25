/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:32:52 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/31 15:40:29 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int i, int p)
{
	long res;

	res = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		res = res * i;
		p--;
	}
	if (res > 2147483647 || res < -2147483648)
		return (0);
	return ((int)res);
}
