/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:28:42 by tadey             #+#    #+#             */
/*   Updated: 2018/02/19 12:34:14 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** func converts characer string representing an integer to an int.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					i;
	int					sign;

	sign = 0;
	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > 9223372036854775807)
		return ((sign == 1) ? 0 : -1);
	if (sign == 1)
		return (-result);
	else
		return (result);
}
