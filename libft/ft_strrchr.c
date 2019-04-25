/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 01:29:01 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/02 18:14:02 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int point;

	point = ft_strlen(s);
	while (point >= 0)
	{
		if (s[point] == c)
			return (char*)(&s[point]);
		point--;
	}
	return (NULL);
}
