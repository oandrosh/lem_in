/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:58:12 by oandrosh          #+#    #+#             */
/*   Updated: 2019/03/18 15:47:22 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_list	*chose_list(t_list **in, const int fd)
{
	t_list	*temp;

	temp = *in;
	while (temp != NULL)
	{
		if (temp->content_size == (size_t)fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("", 1);
	temp->content_size = (size_t)fd;
	ft_lstadd(in, temp);
	return (temp);
}

static int		reading(const int fd, char *buf, t_list **tres)
{
	int		readm;
	char	*temp;

	while ((readm = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[readm] = '\0';
		temp = (*tres)->content;
		(*tres)->content = ft_strjoin((*tres)->content, buf);
		free(temp);
		if (ft_strchr(buf, '\n') != '\0')
			break ;
	}
	return (readm);
}

static int		addline(char **line, char *res)
{
	size_t i;

	i = 0;
	if (res == NULL)
		return (0);
	while (res[i] != '\n' && res[i])
		i++;
	*line = ft_strsub(res, 0, i);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	static t_list	*res;
	t_list			*tres;
	int				i;

	i = 0;
	if (fd < 0 || (read(fd, buf, 0)) < 0 || !line)
		return (-1);
	tres = chose_list(&res, fd);
	i = reading(fd, buf, &tres);
	temp = tres->content;
	if (i <= 0 && !*temp)
		return (0);
	i = addline(line, tres->content);
	if (temp[i] != '\0')
	{
		tres->content = ft_strdup(&temp[i + 1]);
		free(temp);
	}
	else
		temp[0] = '\0';
	return (1);
}
