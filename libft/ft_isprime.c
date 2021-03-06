/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:17:41 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/03 11:02:22 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprime(int i)
{
	int x;

	if (i == 1)
		return (0);
	x = 2;
	while (x * x <= i)
	{
		if (i % x == 0)
			return (0);
		x++;
	}
	return (1);
}
