/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 02:00:20 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/01 14:44:24 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *src, char const *need, size_t l)
{
	size_t i;
	size_t j;

	i = 0;
	if (need[i] == '\0')
		return ((char*)&src[i]);
	while (src[i] != '\0' && i < l)
	{
		j = 0;
		if (src[i] == need[j])
		{
			while (src[i + j] == need[j] && need[j] && i + j < l)
				j++;
			if (need[j] == '\0')
				return ((char*)&src[i]);
		}
		i++;
	}
	return (NULL);
}
