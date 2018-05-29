/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:05:40 by tadey             #+#    #+#             */
/*   Updated: 2017/12/07 13:27:48 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**memset is used to fill a block of mem w particular value. sets len bytes of
** the string b to the value of c.
*/

#include "libft.h"

void	ft_memset(void **b, int c, size_t len)
{
	size_t i;

	i = -1;
	while (++i < len)
		((int *)*b)[i] = c;
}
