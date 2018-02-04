/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:03:58 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/22 20:43:16 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!(sub = ft_strnew(len)) || !s)
		return (NULL);
	i = start;
	while (s[i] && i - start < len)
	{
		sub[i - start] = s[i];
		i++;
	}
	return (sub);
}
