/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:58:55 by tadey             #+#    #+#             */
/*   Updated: 2017/10/28 22:31:19 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**func that returns the square root of a number.
*/

#include "libft.h"

int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i < 46342)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}
