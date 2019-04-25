/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:13:08 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/29 17:24:11 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		i;
	char	*res;

	i = 0;
	res = (char*)malloc(size);
	if (res == 0)
		return (0);
	while (size > 0)
	{
		res[size - 1] = 0;
		size--;
	}
	return (res);
}
