/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 01:09:50 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/02 18:15:38 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	int point;

	point = 0;
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (s[point])
	{
		if (s[point] == c)
			return ((char*)s + point);
		point++;
	}
	return (0);
}
