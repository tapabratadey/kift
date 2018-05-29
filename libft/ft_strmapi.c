/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 23:01:39 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 23:14:48 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**allocates space for the char string resulting from applying func f to each
**char in s, passing the index as the first argument.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*c;

	i = -1;
	if (f == NULL || s == NULL)
		return (NULL);
	if ((c = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[++i])
		c[i] = (*f)(i, s[i]);
	c[i] = '\0';
	return (c);
}
