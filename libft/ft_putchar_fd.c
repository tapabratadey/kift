/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:47:28 by tadey             #+#    #+#             */
/*   Updated: 2017/12/07 23:48:21 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**writes the char c to file descriptor passed into it.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
