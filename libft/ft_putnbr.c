/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:30:07 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 14:38:20 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**writes numbers int type.
*/

#include "libft.h"

static void		overflow(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void			ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		overflow();
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * (-1);
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar('0' + nb % 10);
	}
}
