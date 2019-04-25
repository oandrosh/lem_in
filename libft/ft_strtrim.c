/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:48:52 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/30 10:39:29 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char const *s)
{
	int i;

	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s)
	{
		i++;
		s++;
	}
	while ((*(s - 1) == ' ' || *(s - 1) == '\n' || *(s - 1) == '\t') && i > 0)
	{
		s--;
		i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		j;
	char	*res;

	if (s == 0)
		return (NULL);
	j = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	res = (char*)malloc(len(s) + 1);
	if (res == 0)
		return (NULL);
	while (*s)
	{
		res[j] = *s;
		s++;
		j++;
	}
	while (res[j - 1] == ' ' || res[j - 1] == '\n' || res[j - 1] == '\t')
		j--;
	res[j] = '\0';
	return (res);
}
