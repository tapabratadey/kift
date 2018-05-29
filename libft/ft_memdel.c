/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:44:21 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 15:09:55 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**frees the mem pointed to by the input. it then sets the first pointer pointed
** to by ap to NULL.
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
