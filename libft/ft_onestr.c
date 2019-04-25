/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onestr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:59:42 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/31 17:16:24 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(char const **s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		len = len + ft_strlen(s[i]) + 1;
		i++;
	}
	return (len);
}

char		*ft_onestr(char const **s, char c)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len;

	if (s != NULL || *s != NULL)
	{
		len = length(s) - 1;
		if ((res = (char*)malloc(len)))
		{
			i = 0;
			res[len] = '\0';
			while (s[i])
			{
				j = 0;
				while (s[i][j])
					res[--len] = s[i][j++];
				if (len == 0)
					return (ft_strrev(res));
				res[--len] = c;
				i++;
			}
		}
	}
	return (NULL);
}
