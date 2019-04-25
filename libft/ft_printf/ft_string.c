/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:52:39 by oandrosh          #+#    #+#             */
/*   Updated: 2019/02/07 11:50:34 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	minus(char *str, int *flags)
{
	ft_joinstrn(str, flags[7]);
	if (flags[6] > flags[7])
	{
		if (flags[7] > 0 && flags[7] < ft_strlen(str))
			ft_joinchar(' ', flags[6] - flags[7]);
		else
			ft_joinchar(' ', flags[6] - ft_strlen(str));
	}
}

static void	nominus(char *str, int *flags)
{
	char a;

	a = ' ';
	if (flags[4] == 1)
		a = '0';
	if (flags[7] > 0 && flags[6] > flags[7] && flags[7] < ft_strlen(str))
		ft_joinchar(a, flags[6] - flags[7]);
	else if (flags[6] > (int)ft_strlen(str))
		ft_joinchar(a, flags[6] - ft_strlen(str));
	ft_joinstrn(str, flags[7]);
}

void		ft_string(int *flags, va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	if (ft_strlen(str) == 0)
		flags[7] = 0;
	if (flags[0] == 1)
		minus(str, flags);
	else
		nominus(str, flags);
}
