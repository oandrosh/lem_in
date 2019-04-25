/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:13:04 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/13 18:13:06 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	write_line(t_ways **output)
{
	t_ways	*tmp;

	tmp = *output;
	while (tmp)
	{
		if (tmp->way)
		{
			ft_printf("L%d-%s", tmp->len, tmp->way->link->name);
			tmp->way = tmp->way->next;
			tmp = tmp->next;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->way)
		{
			ft_printf(" L%d-%s", tmp->len, tmp->way->link->name);
			tmp->way = tmp->way->next;
		}
		tmp = tmp->next;
	}
	g_lines++;
	ft_printf("\n");
}

void	fast_output(t_rooms *r2, t_lines **src)
{
	int		ant_num;

	ft_printf("\n");
	print_input(*src);
	ant_num = 1;
	ft_printf("\n");
	while (ant_num < g_ants)
	{
		ft_printf("L%d-%s ", ant_num, r2->name);
		ant_num++;
	}
	ft_printf("L%d-%s\n", ant_num, r2->name);
	exit(0);
}

int		check_output(t_ways **output)
{
	t_ways *tmp;

	tmp = *output;
	while (tmp)
	{
		if (tmp->way)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	clear_output(t_ways **output)
{
	t_ways	*freed;

	freed = *output;
	if (!output)
		return ;
	while (freed != NULL)
	{
		free(freed);
		freed = freed->next;
		*output = NULL;
	}
}

void	output(t_ways **ways)
{
	t_ways	*output;
	t_ways	*tmp;
	int		n;

	output = NULL;
	n = 1;
	tmp = output;
	while (n > 0)
	{
		sent_ant(ways, &output);
		write_line(&output);
		n = check_output(&output);
	}
	clear_output(&output);
}
