/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 23:46:42 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 23:51:17 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**allocates space for the substring contained inside character
**string s that begins at start and has length len.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	i = 0;
	if (s == NULL || len == 0)
		return (ft_strdup(""));
	if ((c = ft_strnew(len)) == NULL)
		return (NULL);
	while (i < len)
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
