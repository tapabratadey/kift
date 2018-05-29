/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:38:42 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 11:54:01 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**locates the last occurence of c in the char string s.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	while (len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		len--;
	}
	return (NULL);
}
