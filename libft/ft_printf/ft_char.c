/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:00:58 by oandrosh          #+#    #+#             */
/*   Updated: 2019/01/28 12:01:40 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_char(int *flags, char a)
{
	if (flags[4] == 1 && flags[0] != 1)
	{
		if (flags[6] > 1)
			ft_joinchar('0', flags[6] - 1);
	}
	else if (flags[0] != 1 && flags[6] > 1)
		ft_joinchar(' ', flags[6] - 1);
	if (a == 0)
		ft_joinchar(0, 1);
	else
		ft_joinchar(a, 1);
	if (flags[0] == 1 && flags[6] > 1)
		ft_joinchar(' ', flags[6] - 1);
}
