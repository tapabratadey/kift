/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:31:10 by tadey             #+#    #+#             */
/*   Updated: 2017/12/11 12:31:35 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**delt an entire list and all its elements
**alst is a list, del() is the func to dlt whatever is in its first parameter
**(same as the delete in the delone method)
**create temp vars
**if the list is empty, there is nothing to do, so just return nothing to exit
**func.
**store the first element of the list as the temp var current
**loop to delete all the elements in the list
**while current is not NULL (non-existing)
**set the temp var to current to store the value we want to delte after
**make current the next value of it, we can do this, bc we already stored
**current in temp, so we haven't lost current yet.
**now dlte the element that was current, baasically dlte the element at the
**..current spot
**now that current is NUll, all element are dleted, we have to make the pointer
**..for the main list null to clean it up for sure.
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*current;

	if (!(alst && *alst))
		return ;
	current = *alst;
	while (current)
	{
		temp = current;
		current = current->next;
		ft_lstdelone(&temp, del);
	}
	*alst = NULL;
}
