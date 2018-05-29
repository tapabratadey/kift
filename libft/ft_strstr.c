/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:40:41 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 12:44:26 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**locates the first occurence of char string little in the big.
*/

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t i;

	i = 0;
	if (to_find[0] == '\0')
		return (char *)(str);
	while (str[i] != '\0')
	{
		i = 0;
		while (str[i] == to_find[i])
		{
			if (to_find[++i] == '\0')
				return (char *)(str);
		}
		str++;
	}
	return (0);
}
