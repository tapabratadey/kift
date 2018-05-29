/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 00:17:01 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 14:39:39 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**writes integer n to the file descriptor fd.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int converter;

	converter = n;
	if (converter == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		converter = -converter;
		ft_putchar_fd('-', fd);
	}
	if (converter >= 10)
	{
		ft_putnbr_fd(converter / 10, fd);
		ft_putchar_fd(converter % 10 + '0', fd);
	}
	else
		ft_putchar_fd('0' + converter, fd);
}
