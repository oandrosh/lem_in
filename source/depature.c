/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depature.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:45:14 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/16 18:50:03 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		find_exp(t_ways *way, t_ways **ways, int ant_num)
{
	t_ways	*tmp;
	int		exp;

	exp = 0;
	tmp = (*ways);
	while (tmp->num < way->num)
	{
		exp += way->len - tmp->len;
		tmp = tmp->next;
	}
	if (g_ants - ant_num < exp)
		return (0);
	return (1);
}

int		sent_or_no(t_ways *way, t_ways **ways, t_ways **output, int ant_num)
{
	t_ways	*tmp;
	t_ways	*new;

	if (find_exp(way, ways, ant_num) == 0)
		return (0);
	new = (t_ways*)malloc(sizeof(t_ways));
	new->way = way->way;
	new->len = ant_num;
	new->next = NULL;
	if (!(*output))
	{
		(*output) = new;
		return (1);
	}
	tmp = *output;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}

int		sent_ant(t_ways **ways, t_ways **output)
{
	t_ways		*tmp;
	static int	ant_num = 1;

	tmp = *ways;
	if (ant_num > g_ants)
		return (0);
	while (ant_num <= g_ants && tmp)
	{
		if (sent_or_no(tmp, ways, output, ant_num) == 1)
			ant_num++;
		else
			break ;
		tmp = tmp->next;
	}
	return (1);
}
