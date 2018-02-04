/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:58:25 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/21 11:51:42 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *d, const void *s, size_t len)
{
	size_t	i;

	i = 0;
	if (!d || !s)
		return (NULL);
	if (s < d)
		while (len)
		{
			len--;
			*(char*)(d + len) = *(char*)(s + len);
		}
	else
		while (i < len)
		{
			*(char*)(d + i) = *(char*)(s + i);
			i++;
		}
	return (d);
}
