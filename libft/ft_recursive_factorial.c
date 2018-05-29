/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:58:37 by tadey             #+#    #+#             */
/*   Updated: 2017/10/28 22:14:50 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**recursive implementaion of factorial sequence
*/

int	ft_recursive_factorial(int nb)
{
	if ((nb == 0) || (nb == 1))
		return (1);
	if ((nb < 0) || (nb > 12))
		return (0);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}
