/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:02:32 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 22:50:41 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**allocates space for a copy of the char string s1.
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = src[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}
