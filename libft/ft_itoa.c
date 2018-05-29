/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:15:21 by tadey             #+#    #+#             */
/*   Updated: 2017/12/11 15:02:13 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function returns the absolute value of the input
*/

static long int		ft_abs(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

/*
** function calculates the number of digits in the integer to
** determine the required length of the character string.
*/

static int			ft_len(long int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

/*
** function converts integer to character string
*/

char				*ft_itoa(int nbr)
{
	int			len;
	int			sign;
	char		*c;

	sign = (nbr < 0) ? -1 : 1;
	len = ft_len(nbr);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (NULL);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(nbr % 10);
		nbr = ft_abs(nbr / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
