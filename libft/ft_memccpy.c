/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:04:52 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 22:59:53 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**copies n bytes from void string src to dst. if c is found in src, the func.
**stops copying and returns a pointer to the subsequent byte value.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *cdst;
	unsigned char *csrc;
	unsigned char converter;

	converter = (unsigned char)c;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (n > 0)
	{
		if (*csrc == converter)
		{
			*cdst = converter;
			cdst++;
			return (cdst);
		}
		*cdst = *csrc;
		cdst++;
		csrc++;
		n--;
	}
	return (NULL);
}
