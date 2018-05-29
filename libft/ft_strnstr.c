/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:57:21 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 17:47:37 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**locates the first occurence of character string little in the first len chars
**of big.
*/

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	char	*to_find_start;
	int		steps;

	if (*to_find == '\0')
		return ((char *)str);
	to_find_start = (char *)to_find;
	steps = 0;
	while (*str && (steps < (int)len))
	{
		i = 0;
		while (*str == *to_find && (steps < (int)len))
		{
			if (*(to_find + 1) == '\0')
				return ((char *)(str - i));
			i++;
			str++;
			to_find++;
			steps++;
		}
		str = str - i + 1;
		to_find = to_find_start;
		steps = steps - i + 1;
	}
	return (NULL);
}
