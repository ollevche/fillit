/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:20:12 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/15 17:24:01 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if (*(char*)(s1 + i) != *(char*)(s2 + i))
			return ((*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i)));
		i++;
	}
	return (0);
}
