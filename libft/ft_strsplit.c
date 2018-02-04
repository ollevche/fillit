/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:50:27 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 21:09:39 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*getword(char const *s, char c, size_t ind)
{
	size_t	i;
	char	*w;

	i = 0;
	while (*(s + 1) && i < ind)
	{
		if (*s != c && *(s + 1) == c)
			i++;
		s++;
	}
	while (*s && *s == c)
		s++;
	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	if (!(w = ft_strnew(i + 2)))
		return (NULL);
	i = 0;
	while (*(s + i) && *(s + i) != c)
	{
		*(w + i) = *(s + i);
		i++;
	}
	return (w);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	size;

	size = ft_wordcount(s, c);
	i = 0;
	if (!s || !(res = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(res[i] = getword(s, c, i)))
		{
			while (i)
			{
				free(res[i - 1]);
				i--;
			}
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = 0;
	return (res);
}
