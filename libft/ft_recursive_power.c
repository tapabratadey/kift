/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:13:32 by tadey             #+#    #+#             */
/*   Updated: 2017/10/28 22:29:46 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**recursive implementaion that returns the value of a power applied to a number.
*/

#include "libft.h"

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, (power - 1)));
}
