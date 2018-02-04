/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:46:09 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 20:20:17 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	void	*ptr;

	if (!dst || !src)
		return (NULL);
	i = 0;
	ptr = NULL;
	while (i < n)
	{
		*(char*)dst = *(char*)src;
		if (*(char*)src == (char)c)
		{
			ptr = dst + 1;
			break ;
		}
		i++;
		dst++;
		src++;
	}
	return (ptr);
}
