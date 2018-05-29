/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:17:49 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 22:45:31 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**concatenates character string s2 to s1.
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *ret;

	ret = s1;
	while (*s1)
		s1++;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (ret);
}
