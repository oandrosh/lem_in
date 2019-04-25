/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:22:37 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/11 13:22:40 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	enqueue(t_links **queue, t_rooms *room)
{
	t_links	*tmp;

	tmp = (t_links*)malloc(sizeof(t_links));
	tmp->link = room;
	tmp->next = *queue;
	*queue = tmp;
	room->enqueued = true;
}

void	enqueue_links(t_links *rooms, t_links **queue, t_rooms *prev)
{
	if (prev->type == 'e')
		return ;
	while (rooms)
	{
		if (rooms->link->used == false && rooms->link->enqueued == false &&
			rooms->link->visited == false)
		{
			if (rooms->link->lvl == -1)
				rooms->link->lvl = prev->lvl + 1;
			rooms->link->prev = prev;
			enqueue(queue, rooms->link);
		}
		rooms = rooms->next;
	}
}

t_rooms	*dequeue(t_links **queue)
{
	t_links	*tmp;
	t_rooms *room;

	if (!(*queue)->next)
		room = (*queue)->link;
	else
	{
		tmp = *queue;
		while (tmp->link->visited == false)
		{
			room = tmp->link;
			tmp = tmp->next;
		}
	}
	return (room);
}

void	del_queue(t_links **queue)
{
	t_links	*freed;

	freed = *queue;
	if (!queue)
		return ;
	while (freed != NULL)
	{
		free(freed);
		freed = freed->next;
		*queue = NULL;
	}
}
