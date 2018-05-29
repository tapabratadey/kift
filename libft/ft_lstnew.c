/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:38:26 by tadey             #+#    #+#             */
/*   Updated: 2017/12/16 01:57:25 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**returns a new t_list (list item) with contents
**content = stuff you wanna add, content_size = the size of the contents
**protecting malloc
**if there's no contents passed
**create a blank element
**if content exists
**allocate a size for the contents
**using the ft_memcpy the contents will be copied into the content spot
**and then the size will also be noted
**Make it's next value null, because it's assumed to be added to the end of some
**list (basically some element will have a ->next that will point to this elmnt
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
