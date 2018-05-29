/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 23:03:55 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 23:02:05 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**allocates the first occurence of c in the first n bytes of void string s.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char converter;
	unsigned char *cs;

	converter = c;
	cs = (unsigned char *)s;
	while (n > 0)
	{
		if (*cs == converter)
			return (cs);
		cs++;
		n--;
	}
	return (NULL);
}
