/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:33:13 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/01 14:03:15 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *freed;

	if (alst && del)
	{
		freed = *alst;
		del(freed->content, freed->content_size);
		*alst = NULL;
		freed->next = NULL;
		free(freed);
	}
}
