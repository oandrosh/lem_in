/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:39:20 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/31 15:02:07 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s1)
{
	char	*s2;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	if ((s2 = (char*)malloc(j + 1)))
	{
		while (i < j)
		{
			s2[i] = s1[j - i - 1];
			i++;
		}
	}
	return (s2);
}
