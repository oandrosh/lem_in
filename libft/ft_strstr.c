/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 01:35:12 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/01 14:40:39 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *src, char const *needle)
{
	int		i;
	int		j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)&src[i]);
	while (src[i] != '\0')
	{
		j = 0;
		if (src[i] == needle[j])
		{
			while (src[i + j] == needle[j] && needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char*)&src[i]);
		}
		i++;
	}
	return (NULL);
}
