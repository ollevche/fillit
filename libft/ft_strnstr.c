/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:07:00 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 18:05:19 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t n;

	if (!big || !little)
		return (NULL);
	n = 0;
	while (*big && n < len)
	{
		i = 0;
		while (little[i] && big[i] && big[i] == little[i] && i + n < len)
			i++;
		if (!little[i])
			return ((char*)big);
		big++;
		n++;
	}
	return (NULL);
}
