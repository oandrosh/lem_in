/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:58:24 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/18 15:47:51 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	res = (char*)malloc(len + 1);
	if (res == 0)
		return (NULL);
	while (i <= len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
