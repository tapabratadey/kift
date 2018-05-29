/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:34:38 by tadey             #+#    #+#             */
/*   Updated: 2017/12/11 12:34:56 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Ft_lstmap allocates space for the list that results from applying the
**  function f to the link lst and every successive link connected to it.
*/

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst)
	{
		new = f(lst);
		new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
