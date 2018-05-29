/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:34:18 by tadey             #+#    #+#             */
/*   Updated: 2017/12/07 01:04:08 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**copies the null-terminated character string src to dst.
*/

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *p;

	p = dst;
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = *src;
	return (p);
}
