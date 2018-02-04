/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoverlap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:55:42 by ollevche          #+#    #+#             */
/*   Updated: 2017/11/21 13:12:20 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isoverlap(char *sub, char *str)
{
	size_t i;

	if (!sub || !str)
		return (0);
	while (*sub)
	{
		i = 0;
		while (sub != (str + i) && str[i])
			i++;
		if (sub == (str + i))
			return (1);
		sub++;
	}
	return (0);
}
