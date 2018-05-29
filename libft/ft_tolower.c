/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:01:05 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 17:51:48 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**returns char string in lowercase if the chars is uppercase.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
