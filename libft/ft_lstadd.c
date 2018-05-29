/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:32:16 by tadey             #+#    #+#             */
/*   Updated: 2017/12/11 12:32:34 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** add the element new at the beginning of the list.
**alst = first elment in list, new = element to add.
**create a temp node.
**check if there is no first element (empty list)
**make the fist node become the new new node
**and stop there
**if there is no first element, then make the temp node to the new element
**then make the temp node (the new element) above's next element
**then make the new first elements pointer the element we want to add.
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!(alst && *alst))
	{
		*alst = new;
		return ;
	}
	new->next = *alst;
	*alst = new;
}
