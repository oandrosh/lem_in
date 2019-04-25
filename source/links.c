/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:35:46 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/06 17:35:49 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	make_link(char *str1, char *str2, t_rooms **rooms, t_lines **src)
{
	t_links *new;
	t_rooms	*r1;
	t_rooms *r2;
	t_rooms	*tmp;

	tmp = *rooms;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, str1) == 0)
			r1 = tmp;
		if (ft_strcmp(tmp->name, str2) == 0)
			r2 = tmp;
		tmp = tmp->next;
	}
	if (!r1 || !r2 || ft_strcmp(r1->name, r2->name) == 0)
		print_error(7);
	new = (t_links*)ft_memalloc(sizeof(t_links));
	new->link = r2;
	new->next = r1->links;
	r1->links = new;
	new = NULL;
	if (r1->type == 's' && r2->type == 'e')
		fast_output(r2, src);
}

int		define_links(char *str, t_rooms **rooms, t_lines **src)
{
	int		i;
	char	*str1;
	char	*str2;
	t_rooms	*tmp;

	i = 0;
	tmp = (*rooms);
	while (str[i] && str[i] != '-')
		i++;
	if (str[i] != '-')
		return (print_error(6));
	str1 = ft_strsub(str, 0, i);
	str2 = ft_strdup(ft_strchr(str, '-') + 1);
	make_link(str1, str2, rooms, src);
	make_link(str2, str1, rooms, src);
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (1);
}
