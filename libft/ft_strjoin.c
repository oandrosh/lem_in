/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:09:49 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/29 12:23:07 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	if (s1 != 0 && s2 != 0)
	{
		i = 0;
		j = 0;
		res = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (res == 0)
			return (NULL);
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			res[i + j] = s2[j];
			j++;
		}
		res[i + j] = '\0';
		return (res);
	}
	return (NULL);
}
