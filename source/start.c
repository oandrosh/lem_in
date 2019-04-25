/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 06:15:29 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/07 06:15:33 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	write_ways(t_links *way, t_ways **ways)
{
	t_ways	*tmp;
	t_ways	*new;
	t_links	*current;

	new = (t_ways*)malloc(sizeof(t_ways));
	new->len = 0;
	new->next = NULL;
	current = way;
	while (current)
	{
		current = current->next;
		new->len++;
	}
	new->way = way;
	if (!(*ways))
	{
		new->num = 1;
		(*ways) = new;
		return ;
	}
	tmp = *ways;
	while (tmp->next)
		tmp = tmp->next;
	new->num = tmp->num + 1;
	tmp->next = new;
}

t_links	*create_ways(t_rooms *end, t_links *way)
{
	t_links *tmp;
	t_rooms	*current;

	way = NULL;
	current = end;
	while (current->type != 's')
	{
		tmp = (t_links*)malloc(sizeof(t_links));
		tmp->link = current;
		tmp->next = way;
		way = tmp;
		current = current->prev;
		if (current->type != 'e')
			current->used = true;
	}
	return (way);
}

void	unmark_rooms(t_rooms **rooms)
{
	t_rooms	*tmp;

	tmp = *rooms;
	while (tmp)
	{
		if (tmp->enqueued == true)
			tmp->enqueued = false;
		if (tmp->visited == true)
			tmp->visited = false;
		tmp = tmp->next;
	}
}

int		my_bfs(t_rooms **start, t_rooms **rooms, t_rooms *end)
{
	t_links	*queue;
	t_rooms	*tmp;

	if (!*start || !end)
		print_error(4);
	queue = NULL;
	enqueue(&queue, *start);
	while (queue->link->visited == false)
	{
		tmp = dequeue(&queue);
		tmp->enqueued = false;
		tmp->visited = true;
		if (tmp->type == 'e')
		{
			del_queue(&queue);
			unmark_rooms(rooms);
			return (1);
		}
		enqueue_links(tmp->links, &queue, tmp);
	}
	del_queue(&queue);
	return (0);
}

void	start(t_rooms **rooms, t_ways **ways)
{
	t_rooms *start;
	t_rooms *end;
	t_links	*way;

	start = *rooms;
	end = *rooms;
	while (start)
	{
		if (start->type == 's')
			break ;
		start = start->next;
	}
	while (end)
	{
		if (end->type == 'e')
			break ;
		end = end->next;
	}
	while (my_bfs(&start, rooms, end) == 1)
	{
		way = create_ways(end, way);
		write_ways(way, ways);
	}
	if (!*ways)
		print_error(10);
}
