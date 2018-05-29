/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:41:09 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 15:44:50 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**sets the value of every character in character string s to '\0'
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}
