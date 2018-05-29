/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 04:23:21 by tadey             #+#    #+#             */
/*   Updated: 2018/05/29 04:23:23 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef KIFT_H
# define KIFT_H
#include <pocketsphinx.h>
#include "libft/libft.h"

typedef struct s_config
{
	int				read_voice;
	int32			score;
	char const		*hypths;
	size_t			nsamp;
	FILE			*file;
}				t_config;
#endif
