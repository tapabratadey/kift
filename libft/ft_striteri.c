/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:21:28 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 16:36:40 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**applies the func f to each char in the char string s, passing the index as the
**first argument.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	i = 0;
	if (s && f)
	{
		while (*s)
		{
			f(i, s);
			s++;
			i++;
		}
	}
}
