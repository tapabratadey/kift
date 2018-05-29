/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:59:00 by tadey             #+#    #+#             */
/*   Updated: 2017/12/11 12:00:42 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Delete one element from the list
**alst = list element to delete, del() is the func to dlt the contents of the
**..alst (because the content of the alst need to be cleaned from memory or it
**will become junk)
**if the alst pointer exists and it does point to something that exists, then:
**..use the dlt func. to dlt the contents of the list(free that memory)
**then free the element's pointer from memory
**set it to null to ensure no memory junk
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst && *alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
