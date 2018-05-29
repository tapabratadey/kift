/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:16:57 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 14:40:05 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**writes a character.
*/

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}