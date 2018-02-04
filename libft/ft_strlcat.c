/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:03:54 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 20:35:28 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d;
	size_t s;
	size_t ret;

	if (!dst || !src)
		return (0);
	if (!size)
		return (ft_strlen(src));
	d = ft_strlen(dst);
	s = 0;
	ret = ft_strlen(dst) + ft_strlen(src);
	if (d >= size)
		ret = ft_strlen(src) + size;
	while (src[s] && d + 1 < size)
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	if (dst + d)
		dst[d] = 0;
	return (ret);
}
