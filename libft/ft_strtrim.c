/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:20:08 by tadey             #+#    #+#             */
/*   Updated: 2017/12/10 23:13:32 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**returns a copy of the string arg without whitespaces at the beg/end of the
**string. if s has no whitespaces at the beg/end, the func returns a copy of s.
**If the allocation fails the function returns NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*new;

	if (s == 0)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	len = ft_strlen(s);
	i = len - 1;
	if (len > 0)
		while (ft_isspace(s[i]))
			i--;
	if ((new = ft_strnew(i + 1)) == NULL)
		return (NULL);
	len = 0;
	while (s[len] && len <= i)
	{
		new[len] = s[len];
		len++;
	}
	new[len] = '\0';
	return (new);
}
