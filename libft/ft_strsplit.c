/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 00:43:56 by tadey             #+#    #+#             */
/*   Updated: 2017/12/11 00:44:42 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**counts the number of words separated by char c in the char string.
*/

static int				ft_countwords(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s == c)
			s++;
		i++;
	}
	return (i);
}

/*
**writes the word from char string s to the array of char strings passed into it
*/

static size_t			ft_fillword(char **ptr, char const *s, char c, int i)
{
	size_t		shift;
	size_t		wlen;

	shift = 0;
	wlen = 0;
	while (*s == c)
	{
		s++;
		shift++;
	}
	while (s[wlen] && s[wlen] != c)
		wlen++;
	if (wlen > 0)
	{
		ptr[i] = ft_strnew(wlen);
		ptr[i] = ft_strncpy(ptr[i], s, wlen);
	}
	return (shift + wlen);
}

/*
**splits the character string passed into by at each
**  c character, and adds the words into an array of character strings.
*/

char					**ft_strsplit(char const *s, char c)
{
	int			i;
	int			wcount;
	char		**ptr;
	size_t		shift;

	if (s == NULL || c == '\0')
		return (NULL);
	i = 0;
	shift = 0;
	wcount = ft_countwords(s, c);
	if ((ptr = (char **)malloc(sizeof(char *) * ++wcount)) == NULL)
		return (NULL);
	while (*s && i < wcount - 1)
	{
		shift = ft_fillword(ptr, s, c, i);
		s += shift;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
