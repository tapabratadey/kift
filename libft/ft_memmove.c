/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:05:25 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 23:00:50 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**copies len bytes from byte string src to dst. Unlike ft_memcpy, this func
**handles overlapping between src and dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *csrc;
	char *cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	if (len == 0 || cdst == csrc)
		return (dst);
	while (len > 0)
	{
		if (cdst < csrc)
		{
			*cdst = *csrc;
			cdst++;
			csrc++;
			len--;
		}
		else
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	return (dst);
}
