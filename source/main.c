/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:01:38 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/06 16:01:42 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	usage(int ac, char **av)
{
	int		index;

	index = 0;
	while (++index < ac)
	{
		if (!ft_strequ(av[index], "-w") && !ft_strequ(av[index], "-n"))
		{
			ft_printf("\nusage: lem-in [flags [-w]|[-n]] < [file]\n\t");
			ft_printf("Flags:\n\t\t[-w] - show all usable ways\n\t\t[-n]");
			ft_printf(" - show total quantity of lines\n\tFile format:");
			ft_printf("\n\t\tnumber_of_ants\n\t\tthe_rooms[name][x][y]");
			ft_printf("\n\t\tthe_links\n");
			exit(0);
		}
	}
}

void	print_ways(t_ways **ways)
{
	t_ways	*tmp;
	t_links	*way;

	tmp = *ways;
	ft_printf("\n\tSuch ways was found:\n");
	while (tmp)
	{
		ft_printf("\t\t%s", tmp->way->link->prev->name);
		way = tmp->way;
		while (way)
		{
			ft_printf("-%s", way->link->name);
			way = way->next;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void	use_flags(int ac, char **av, t_ways **ways)
{
	int		index;
	t_ways	*tmp;

	index = 1;
	tmp = *ways;
	while (index < ac)
	{
		if (ft_strequ(av[index], "-w"))
			print_ways(ways);
		else if (ft_strequ(av[index], "-n"))
			printf("\n\tTotal lines: %d\n", g_lines);
		index++;
	}
}

int		main(int ac, char **av)
{
	t_lines	*src;
	t_rooms	*rooms;
	t_ways	*ways;

	ways = NULL;
	src = NULL;
	g_ants = 0;
	g_lines = 0;
	if (ac > 1)
		usage(ac, av);
	input(&src, &rooms);
	start(&rooms, &ways);
	print_input(src);
	ft_printf("\n");
	output(&ways);
	if (ac > 1)
		use_flags(ac, av, &ways);
	return (0);
}
