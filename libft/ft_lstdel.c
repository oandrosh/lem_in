/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:14:05 by oandrosh          #+#    #+#             */
/*   Updated: 2018/11/01 13:56:39 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *freed;

	if (alst || del)
	{
		freed = *alst;
		while (freed != NULL)
		{
			del(freed->content, freed->content_size);
			free(freed);
			freed = freed->next;
			*alst = NULL;
		}
	}
}
