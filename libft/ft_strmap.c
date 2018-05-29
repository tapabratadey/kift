/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 22:32:43 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 23:00:57 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**allocates space for the char string resulting from the application of f
**to each char in s.
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*c;

	i = -1;
	if (f == NULL || s == NULL)
		return (NULL);
	if ((c = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[++i])
		c[i] = (*f)(s[i]);
	c[i] = '\0';
	return (c);
}
