/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:12:21 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/29 12:02:59 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*res;

	i = size;
	res = (char*)malloc(size + 1);
	if (res == 0)
		return (NULL);
	while (i >= 0)
	{
		res[i] = '\0';
		i--;
	}
	return (res);
}
