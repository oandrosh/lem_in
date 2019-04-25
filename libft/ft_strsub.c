/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:35:15 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/18 15:46:16 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s != 0)
	{
		i = 0;
		res = (char*)malloc(len + 1);
		if (res == 0)
			return (NULL);
		while (i < len)
		{
			res[i] = s[i + start];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
