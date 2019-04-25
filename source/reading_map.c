/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:27:33 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/18 12:31:42 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		print_input(t_lines *src)
{
	if (src->next != NULL)
		print_input(src->next);
	if (src->line)
		ft_printf("%s\n", src->line);
	return (0);
}

int		number_of_ants(char *str)
{
	int		i;

	i = 0;
	if (!str[0])
		print_error(6);
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == 0)
			print_error(1);
	}
	g_ants = ft_atoi(str);
	if (g_ants <= 0)
		print_error(1);
	return (1);
}

int		read_line(t_lines **src)
{
	char	*str;
	t_lines	*new;
	int		n;

	n = get_next_line(0, &str);
	if (n == 0)
		return (0);
	if (n < 0)
		print_error(9);
	new = (t_lines*)ft_memalloc(sizeof(t_lines));
	new->line = ft_strdup(str);
	ft_strdel(&str);
	if (new->line[0] == 'L' || new->line[0] == ' ')
		return (print_error(6));
	new->next = (*src);
	(*src) = new;
	return (1);
}

int		start_end_coment(t_lines **src, t_rooms **rooms, int l)
{
	if (ft_strcmp((*src)->line, "##start") == 0)
	{
		if (g_ants == 0)
			print_error(1);
		if (l <= 0 || read_line(src) == 0)
			print_error(8);
		return (define_room((*src), rooms, 's'));
	}
	else if (ft_strcmp((*src)->line, "##end") == 0)
	{
		if (g_ants == 0)
			print_error(1);
		if (l <= 0 || read_line(src) == 0)
			print_error(8);
		return (define_room((*src), rooms, 'e'));
	}
	else
		return (1);
}

void	input(t_lines **src, t_rooms **rooms)
{
	int		l;

	l = 1;
	while (1)
	{
		if (read_line(src) == 0)
			break ;
		if ((*src)->line[0] == '#')
		{
			if (start_end_coment(src, rooms, l) == 0)
				print_error(8);
		}
		else if (g_ants <= 0)
		{
			if (number_of_ants((*src)->line) < 0 && g_ants < 0)
				print_error(1);
		}
		else if (l == 1)
			l = define_room((*src), rooms, 'r');
		else if (define_links((*src)->line, rooms, src) == 0)
			break ;
	}
}
