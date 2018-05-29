/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 23:27:54 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 23:39:58 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**returns 1 if the first n characters in the character string s1 and s2 are
**equal and 0 otherwise.
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	return ((ft_strncmp(s1, s2, n) ? 0 : 1));
}
