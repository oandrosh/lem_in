/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:25:08 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/23 07:07:45 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_joinchar(char c, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putchar(c);
		i++;
		g_count++;
	}
}

void	ft_joinstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		g_count++;
	}
	ft_strdel(&str);
}

void	ft_joinstrn(char *str, int n)
{
	int		i;

	if (n > (int)ft_strlen(str) || n < 0)
		n = (int)ft_strlen(str);
	i = 0;
	while (i < n)
	{
		ft_putchar(str[i]);
		i++;
		g_count++;
	}
}
