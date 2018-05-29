/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:17:59 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 22:44:49 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**calc the length of the char string dst while also not exceeding the size - 1.
** concatenates at most size chars to char string dst. if dst length exceeds
**size, the func does nothing and returns source length and dst length.
*/

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dl;
	size_t		sl;
	size_t		shift;

	i = 0;
	dl = 0;
	sl = ft_strlen(src);
	while (dst[dl] && dl < (size - 1))
		dl++;
	shift = dl;
	if (size == 0 || dl == (size - 1))
		return (sl + size);
	while (i < size - dl - 1)
		dst[shift++] = src[i++];
	dst[shift] = '\0';
	return (sl + dl);
}
