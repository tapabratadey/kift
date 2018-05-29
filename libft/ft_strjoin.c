/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 23:51:51 by tadey             #+#    #+#             */
/*   Updated: 2017/12/09 00:16:47 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**allocates space for the concatenated result of char strings s1 and s2.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	catl;
	char	*c;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	catl = ft_strlen(s1) + ft_strlen(s2);
	if (((c = ft_strnew(catl)) == NULL))
		return (NULL);
	c = ft_strcpy(c, s1);
	return (ft_strcat(c, s2));
}
