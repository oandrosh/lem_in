/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:32:52 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/30 14:17:47 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	if ((new = malloc(sizeof(t_list))))
	{
		new = f(lst);
		if (lst->next)
			new->next = ft_lstmap(lst->next, f);
	}
	else
		new->next = NULL;
	return (new);
}
