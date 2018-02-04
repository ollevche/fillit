/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:37:22 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 18:05:43 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;

	if (!big || !little)
		return (NULL);
	if (!*little)
		return ((char*)big);
	while (*big)
	{
		i = 0;
		while (little[i] && big[i] && big[i] == little[i])
			i++;
		if (!little[i])
			return ((char*)big);
		big++;
	}
	return (NULL);
}
