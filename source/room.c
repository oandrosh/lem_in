/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:48:36 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/06 16:48:38 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		check_room(t_rooms *tmp, t_rooms *new)
{
	if (ft_strcmp(new->name, tmp->name) == 0)
		return (print_error(2));
	if (new->x == tmp->x && new->y == tmp->y)
		return (print_error(3));
	if (new->type == 's' && tmp->type == 's')
		return (print_error(4));
	if (new->type == 'e' && tmp->type == 'e')
		return (print_error(4));
	if (ft_strchr(new->name, '-'))
		return (print_error(5));
	return (1);
}

void	fill_room(char *str, t_rooms **new, char type, int length)
{
	(*new) = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	(*new)->name = ft_strnew(length + 1);
	(*new)->name = ft_strncpy((*new)->name, str, length);
	(*new)->x = ft_atoi(ft_strchr(str, ' '));
	(*new)->y = ft_atoi(ft_strrchr(str, ' '));
	(*new)->links = NULL;
	(*new)->type = type;
	(*new)->next = NULL;
	(*new)->used = false;
	(*new)->visited = false;
	(*new)->enqueued = false;
	(*new)->out = 0;
	(*new)->in = 0;
	(*new)->lvl = -1;
	if (type == 's')
		(*new)->lvl = 0;
	if (type == 'e')
		(*new)->lvl = INT_MAX;
}

int		valid_room(char *str, t_rooms **new, char type)
{
	int	i;
	int	length;
	int	j;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	length = i;
	if (str[i] == '\0')
		return (0);
	if (str[i] == ' ')
		while (str[++i] != ' ' && str[i])
			if (ft_isdigit(str[i]) == 0)
				return (0);
	j = i;
	if (str[i] == ' ')
		while (str[++i])
			if (ft_isdigit(str[i]) == 0)
				return (0);
	if (i <= j + 1)
		return (0);
	fill_room(str, new, type, length);
	return (1);
}

int		define_room(t_lines *src, t_rooms **rooms, char type)
{
	t_rooms	*tmp;
	t_rooms	*new;

	if (valid_room(src->line, &new, type) == 0)
	{
		if (type == 'e' || type == 's')
			print_error(8);
		return (define_links(src->line, rooms, &src) - 1);
	}
	if ((*rooms) != NULL)
	{
		tmp = (*rooms);
		while (tmp->next != NULL)
		{
			if (check_room(tmp, new) == 0)
				return (0);
			tmp = tmp->next;
		}
		if (check_room(tmp, new) == 0)
			return (0);
		tmp->next = new;
	}
	else
		*rooms = new;
	return (1);
}
