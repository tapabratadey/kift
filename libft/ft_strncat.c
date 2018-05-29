/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:45:35 by tadey             #+#    #+#             */
/*   Updated: 2017/12/07 15:25:46 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**concatenates n characters from the characters string s2 to s1.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = s1;
	while (*s1)
		s1++;
	while (i < n && *s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
		i++;
	}
	*s1 = '\0';
	return (ret);
}
