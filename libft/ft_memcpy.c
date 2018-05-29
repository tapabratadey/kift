/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:05:11 by tadey             #+#    #+#             */
/*   Updated: 2017/12/07 13:35:04 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**copies n bytes from byte string src to dst. the two byte strings are assumed
**to be the same length.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;

	cdst = (char *)dst;
	csrc = (char *)src;
	while (n > 0)
	{
		*cdst = *csrc;
		cdst++;
		csrc++;
		n--;
	}
	return (dst);
}
