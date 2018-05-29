/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 23:17:37 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 23:26:16 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**returns 1 if the char strings s1 and s2 are equal and 0 otherwise.
*/

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	return ((ft_strcmp(s1, s2) ? 0 : 1));
}
