/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:30:23 by tadey             #+#    #+#             */
/*   Updated: 2017/12/07 16:54:47 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**allocates w/ malloc and returns a fresh memory area. the mem allocated is init
**to 0. if the alloc fails, the func. returns NULL.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	unsigned int	i;

	i = 0;
	mem = (unsigned char *)malloc(size);
	if (mem)
	{
		while (i < size)
		{
			mem[i] = 0;
			i++;
		}
	}
	return ((void *)mem);
}
