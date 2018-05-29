/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:59:14 by tadey             #+#    #+#             */
/*   Updated: 2017/12/06 17:45:20 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**returns char string in lowercase if the chars is uppercase.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
