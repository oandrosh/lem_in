/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:47:56 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/03 10:53:12 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char c)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c)
			if (s[i + 1] == c || s[i + 1] == '\0')
				res++;
		i++;
	}
	return (res);
}

static int	letters(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		a;

	if (s == 0)
		return (NULL);
	i = -1;
	a = 0;
	if (!(res = (char**)malloc(sizeof(char*) * (words(s, c) + 1))))
		return (NULL);
	while (++i < words(s, c))
	{
		while (s[a] == c)
			a++;
		if ((res[i] = (char*)malloc(letters(&s[a], c) + 1)))
		{
			j = 0;
			while (s[a] != c && s[a] != '\0')
				res[i][j++] = s[a++];
			res[i][j] = '\0';
		}
	}
	res[i] = NULL;
	return (res);
}
