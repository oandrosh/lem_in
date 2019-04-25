/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:02:00 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/06 16:02:02 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/ft_printf.h"

typedef struct	s_lines
{
	char			*line;
	struct s_lines	*next;
}				t_lines;

typedef struct	s_links
{
	struct s_rooms	*link;
	struct s_links	*next;
}				t_links;

typedef struct	s_rooms
{
	char			type;
	char			*name;
	struct s_rooms	*prev;
	int				lvl;
	bool			used;
	bool			enqueued;
	bool			visited;
	int				x;
	int				y;
	int				in;
	int				out;
	struct s_links	*links;
	struct s_rooms	*next;
}				t_rooms;

typedef struct	s_ways
{
	struct s_links	*way;
	int				len;
	int				num;
	struct s_ways	*next;
}				t_ways;

int				g_ants;
int				g_lines;
int				start_end_coment(t_lines **src, t_rooms **rooms, int l);
int				read_line(t_lines **src);
int				number_of_ants(char *str);
int				define_room(t_lines *src, t_rooms **rooms, char type);
int				valid_room(char *str, t_rooms **new, char type);
void			fill_room(char *str, t_rooms **new, char type, int length);
int				check_room(t_rooms *tmp, t_rooms *new);
int				define_links(char *str, t_rooms **rooms, t_lines **src);
void			make_link(char *str1, char *str2, t_rooms **rooms,
	t_lines **src);
int				print_error(int i);
int				print_input(t_lines *src);
void			start(t_rooms **rooms, t_ways **ways);
int				my_bfs(t_rooms **start, t_rooms **rooms, t_rooms *end);
t_rooms			*dequeue(t_links **queue);
void			enqueue_links(t_links *rooms, t_links **queue, t_rooms *prev);
void			enqueue(t_links **queue, t_rooms *room);
void			del_queue(t_links **queue);
int				algoritm(t_rooms **rooms, t_ways **ways);
void			del_useless1(t_rooms **rooms);
void			del_useless2(t_rooms **rooms);
int				del_link(t_rooms *room, t_links *del);
void			del_input(t_rooms **rooms);
void			output(t_ways **ways);
int				check_output(t_ways **output);
void			write_line(t_ways **output);
int				sent_ant(t_ways **ways, t_ways **output);
int				sent_or_no(t_ways *way, t_ways **ways, t_ways **output,
	int ant_num);
void			input(t_lines **src, t_rooms **rooms);
void			fast_output(t_rooms *r2, t_lines **src);
void			use_flags(int ac, char **av, t_ways **ways);
void			print_ways(t_ways **ways);
void			usage(int ac, char **av);

#endif
