/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:38:19 by tadey             #+#    #+#             */
/*   Updated: 2017/12/08 15:39:17 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**deletes the character string pointed to by the input. it then frees the first
**char pointer pointed to by as.
*/

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}
