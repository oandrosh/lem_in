/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 00:31:57 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/31 17:44:18 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t i;
	size_t ilen;
	size_t len;

	i = 0;
	len = 0;
	ilen = ft_strlen(dst);
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	if (dstsize - 1 < ilen)
		return (ft_strlen(src) + dstsize);
	while (dst[len] && len < dstsize)
		len++;
	while (src[i] && (len + i + 1) < dstsize)
	{
		dst[len + i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[len + i] = '\0';
	return (ft_strlen(src) + ilen);
}
