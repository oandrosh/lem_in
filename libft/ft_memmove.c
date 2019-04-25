/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 05:01:15 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/29 16:04:20 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t			i;

	i = 0;
	if ((unsigned char *)src > (unsigned char *)dst)
	{
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
		return (dst);
	}
	while (i < len)
	{
		((unsigned char*)dst)[len - i - 1] = ((unsigned char*)src)[len - i - 1];
		i++;
	}
	return (dst);
}
