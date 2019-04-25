/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:53:02 by oandrosh          #+#    #+#             */
/*   Updated: 2018/10/28 21:30:05 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i] &&
				((unsigned char*)s1)[i] != '\0')
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
