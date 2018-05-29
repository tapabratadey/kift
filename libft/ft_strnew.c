/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:19:54 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 15:24:36 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**allocates space for a new string with size characters.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*fresh;

	i = 0;
	fresh = (char *)malloc(sizeof(char) * (size + 1));
	if (fresh)
	{
		while (i < size + 1)
		{
			fresh[i] = '\0';
			i++;
		}
	}
	return (fresh);
}
