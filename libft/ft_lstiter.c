/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:32:46 by tadey             #+#    #+#             */
/*   Updated: 2017/12/11 12:34:00 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**applies whatever funct you pass as the second parameter to every parameter
**in the list
**lst = the first element in the list, but keep in mind there is only one '*'
**..instead of '**' in front of lst, because lst is not passed by reference,
**..but by value as it had to for delting it above. This is only applying a
**..function to it, so you don't need to change the values in the list.
**f is the function we want to apply to each element
**point current to the value of the first element in the list.
**while the current isn't null, basically increment until you're out of the list
**..indexs where the current is null bc the last elements current->next = Null.
**apply the f funct to current
**increment current to the next val in the list.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*current;

	current = lst;
	while (current)
	{
		f(current);
		current = current->next;
	}
}
