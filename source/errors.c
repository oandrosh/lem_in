/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:23:16 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/18 12:34:05 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		print_error(int i)
{
	if (i == 1)
		ft_putendl("ERROR: wrong number of ants");
	else if (i == 2)
		ft_putendl("ERROR: double initialization of room");
	else if (i == 3)
		ft_putendl("ERROR: too much rooms for one coordinates");
	else if (i == 4)
		ft_putendl("ERROR: need one 'start' and one 'end' rooms");
	else if (i == 5)
		ft_putendl("ERROR: '-' bad character for roomname");
	else if (i == 6)
		ft_putendl("ERROR: bad input");
	else if (i == 7)
		ft_putendl("ERROR: bad link");
	else if (i == 8)
		ft_putendl("ERROR: bad input for 'start' or 'end' room");
	else if (i == 9)
		ft_putendl("ERROR: bad file");
	else if (i == 10)
		ft_putendl("ERROR: no one valid way");
	exit(1);
	return (0);
}
